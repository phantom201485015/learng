
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define MAXSIZE 20
typedef struct{
	char data[MAXSIZE];
	int top;
}chseq;
typedef struct {
	int data[MAXSIZE];
	int top;
}daseq;
void In_To_Post(char str1[MAXSIZE], char str2[MAXSIZE], chseq *charseq);
int Precedence(char op1, char op2);
int caculate(char str2[MAXSIZE], daseq *dataseq, chseq *charseq);
void main(){
	chseq *charseq = (chseq *)malloc(sizeof(chseq));
	daseq *dataseq = (daseq *)malloc(sizeof(daseq));
	charseq->data[MAXSIZE] = { 0 };
	dataseq->data[MAXSIZE] = { 0 };
	charseq->top = -1;
	dataseq->top = -1;
	char str1[MAXSIZE] = { 0 };
	char str2[MAXSIZE] = { 0 };
	char c;
	int i,sum;
	i = 0;
	printf("请输入表达式：");//读取输入的中缀表达式
	scanf_s("%c", &c);

	while (c != '\n'){
		str1[i] = c;
		i++;
		scanf_s("%c", &c);
	};


	In_To_Post(str1, str2, charseq);
	i = i - charseq->top;
	i--;
	while (charseq->top != -1){
		str2[i] = charseq->data[charseq->top];
		charseq->top--;
		i++;
	};
	sum=caculate(str2,dataseq,charseq);
	printf("和为：%d", sum);
	_getch();
};
int Precedence(char op1, char op2){
	if (op1 == '+' || op1 == '-'){
		if (op2 == '*' || op2 == '/'){
			return -1;
		}
		else { return 0; }
	}
	if (op1 == '*' || op1 == '/'){
		if (op2 == '+' || op2 == '-'){
			return 0;
		}
		else { return -1; }
	}
};
void In_To_Post(char str1[MAXSIZE],char str2[MAXSIZE],chseq *charseq){
	int j ;
	int m=0;
	for (j = 0; str1[j] != '\0';j++){
		if (j % 2 == 0){
			str2[m] = str1[j];
			m++;
		}
		else{
			if (charseq->top == -1){
				charseq->top++;
				charseq->data[charseq->top] = str1[j];
			}
			else{
				if (Precedence(str1[j], charseq->data[charseq->top]) == 0){
					charseq->top++;
					charseq->data[charseq->top] = str1[j];
				}
				else{
					while (charseq->top != -1){
						str2[m] = charseq->data[charseq->top];
						m++;
						charseq->top--;
					}
					charseq->top++;
					charseq->data[charseq->top] = str1[j];
				}

				
			}
		}
	}
}
int caculate(char str2[MAXSIZE], daseq *dataseq, chseq *charseq){
	int j;
	int sum=0;
	for (j = 0; str2[j] != '\0'; j++){
		if (str2[j]>47){
			dataseq->top++;
			dataseq->data[dataseq->top] = str2[j] - 48;
		}
		else{
			switch (str2[j]){
			case 42:{sum =dataseq->data[dataseq->top - 1] * dataseq->data[dataseq->top]; dataseq->top--; dataseq->data[dataseq->top] = sum; continue; }
			case 43:{sum =dataseq->data[dataseq->top - 1] + dataseq->data[dataseq->top]; dataseq->top--; dataseq->data[dataseq->top] = sum; continue; }
			case 45:{sum =dataseq->data[dataseq->top - 1] - dataseq->data[dataseq->top]; dataseq->top--; dataseq->data[dataseq->top] = sum; continue; }
			case 47:{sum =dataseq->data[dataseq->top - 1] / dataseq->data[dataseq->top]; dataseq->top--; dataseq->data[dataseq->top] = sum; continue; }
			default:printf("error\n");
			}
		}
	}
	return sum;
}
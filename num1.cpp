#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<conio.h>
typedef struct node{
int coe,exp;
node *next;
}node;
void main(){
	node *h, *p,*q;
	h = (node *)malloc(sizeof(node));
	h->next = NULL;
	q = h;
	printf("�Ƿ���д洢��(Esc�˳�)\n");
	int i = 1;
    double sum;
	sum = 0;
	while (_getch() != 27){
			p = (node *)malloc(sizeof(node));
			printf("��%d��ϵ����",i);
			scanf_s("%d", &p->coe);
			printf("��%dָ����",i);
			scanf_s("%d", &p->exp);
			p->next = NULL;
			q->next = p;
			q = p;
			i++;
			printf("�Ƿ������\n");
	};
	double x,a;
	printf("������x��ֵ");
	scanf_s("%lf", &x);
	p = q = h->next;
	a = pow(x, q->exp);
	while (q != NULL){
		a = a*pow(x, q->exp - p->exp);
		sum = sum + (q->coe)*pow(x, q->exp);
		p = q;
		q = q->next;
	};
	printf("�������Ϊ��%lf", sum);
	_getch();
};


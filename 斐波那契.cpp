// second201485002-4.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdio.h"
#include "stdlib.h"
#define MAXSIZE 20


/****************************4.����a+b&b+a@***********************/
typedef struct {               //�������ڴ��������ַ���
	char data[MAXSIZE];
	int r1;     //���е���
	int f1;     //���е�β
}Queue;

void Panduan(void) {
	//�����ַ������ڶ�����
	char g;
	Queue q1;
	int w = -1;
	int x, y;
	q1.r1 = 0;     //��ʼ��
	q1.f1 = -1;
	printf("\n�������ַ�����");
	for (g = getchar(); g != '@'; g = getchar()) {   //���ַ������������
		q1.data[q1.f1 + 1] = g;
		q1.f1++;
		if (g == '&')
			w = q1.f1;
	}
	if (w != -1) {              //����&
		x = q1.r1;
		y = q1.f1;
		while (q1.data[x] == q1.data[y] && q1.data[x] != '&') {
			x++;
			y--;
		}
		if (x == y&&y == w)
			printf("\n������ϸø�ʽ");
		else
			printf("\n���벻���ϸø�ʽ");
	}
	else
		printf("\n���벻���ϸø�ʽ");
}


int main()
{
	Panduan();
	system("pause");
}


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
	printf("是否进行存储：(Esc退出)\n");
	int i = 1;
    double sum;
	sum = 0;
	while (_getch() != 27){
			p = (node *)malloc(sizeof(node));
			printf("第%d项系数：",i);
			scanf_s("%d", &p->coe);
			printf("第%d指数：",i);
			scanf_s("%d", &p->exp);
			p->next = NULL;
			q->next = p;
			q = p;
			i++;
			printf("是否继续：\n");
	};
	double x,a;
	printf("请输入x的值");
	scanf_s("%lf", &x);
	p = q = h->next;
	a = pow(x, q->exp);
	while (q != NULL){
		a = a*pow(x, q->exp - p->exp);
		sum = sum + (q->coe)*pow(x, q->exp);
		p = q;
		q = q->next;
	};
	printf("所有项和为：%lf", sum);
	_getch();
};


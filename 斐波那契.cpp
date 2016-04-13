// second201485002-4.cpp : 定义控制台应用程序的入口点。
//
#include "stdio.h"
#include "stdlib.h"
#define MAXSIZE 20


/****************************4.形如a+b&b+a@***********************/
typedef struct {               //队列用于存放输入的字符串
	char data[MAXSIZE];
	int r1;     //队列的首
	int f1;     //队列的尾
}Queue;

void Panduan(void) {
	//输入字符串存于队列中
	char g;
	Queue q1;
	int w = -1;
	int x, y;
	q1.r1 = 0;     //初始化
	q1.f1 = -1;
	printf("\n请输入字符串：");
	for (g = getchar(); g != '@'; g = getchar()) {   //将字符串存入队列中
		q1.data[q1.f1 + 1] = g;
		q1.f1++;
		if (g == '&')
			w = q1.f1;
	}
	if (w != -1) {              //含有&
		x = q1.r1;
		y = q1.f1;
		while (q1.data[x] == q1.data[y] && q1.data[x] != '&') {
			x++;
			y--;
		}
		if (x == y&&y == w)
			printf("\n输入符合该格式");
		else
			printf("\n输入不符合该格式");
	}
	else
		printf("\n输入不符合该格式");
}


int main()
{
	Panduan();
	system("pause");
}


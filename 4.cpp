#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define K 10
#define MAXSIZE (K+1)
typedef struct{int data[MAXSIZE];
                int r,f;
               }SeQueue;
int main()
{
    int x=1;
    int max;
    SeQueue q;
    q.r=0;
    q.f=0;
    printf("���������������MAX��");
    scanf("%d",&max);
    if(max==0)
    {
        printf("��");
        return 0;
    }
    do
    {
        q.r=(q.r+1)%MAXSIZE;
        q.data[q.r]=0;
    }while(q.r!=q.f);//��������ÿ��Ԫ������
    q.data[q.r++]=1;//���е�һ��Ԫ��Ϊ1
    while(x<=max)//��x<=max ִ��ѭ��
    {
        if((q.r+1)%MAXSIZE==q.f)//��������ʱ  ���fָ��ָ���Ԫ�أ���fָ���λ
        {
            printf("%d\n",q.data[q.f]);
            q.f=(q.f+1)%MAXSIZE;
        }
        q.data[q.r]=x;//��ǰ���е�ַ��Ӧ��x����
        x=2*q.data[q.r]-q.data[(q.r+1)%MAXSIZE];
        q.r=(q.r+1)%MAXSIZE;//rָ���λ
    }
    printf("����Ϊ�����е����У�\n");
    while(q.f!=q.r)         //�����ǰ�����е�K��Ԫ��
    {
        printf("%d\n",q.data[q.f]);
        q.f=(q.f+1)%MAXSIZE;
    }
}

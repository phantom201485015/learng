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
    printf("请输入您想输入的MAX：");
    scanf("%d",&max);
    if(max==0)
    {
        printf("无");
        return 0;
    }
    do
    {
        q.r=(q.r+1)%MAXSIZE;
        q.data[q.r]=0;
    }while(q.r!=q.f);//将队列中每个元素清零
    q.data[q.r++]=1;//队列第一个元素为1
    while(x<=max)//当x<=max 执行循环
    {
        if((q.r+1)%MAXSIZE==q.f)//当队列满时  输出f指针指向的元素，对f指针进位
        {
            printf("%d\n",q.data[q.f]);
            q.f=(q.f+1)%MAXSIZE;
        }
        q.data[q.r]=x;//当前队列地址对应把x存入
        x=2*q.data[q.r]-q.data[(q.r+1)%MAXSIZE];
        q.r=(q.r+1)%MAXSIZE;//r指针进位
    }
    printf("以下为队列中的序列：\n");
    while(q.f!=q.r)         //输出当前队列中的K个元素
    {
        printf("%d\n",q.data[q.f]);
        q.f=(q.f+1)%MAXSIZE;
    }
}

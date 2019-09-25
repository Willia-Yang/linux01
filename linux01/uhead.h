#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
struct Str{
	int sum;
    float average;	
	};
void uSrand(int *,int);
int uSum(int *,int);
int uShow(int *,int);
void uSort(int *,int);
struct Str uOperate(int *,int);
float uAve(int *,int);
void uWriteTo(int*a[],int num);

#include"uhead.h"
#define NUM 5

int main(){
	int a[NUM];
	struct Str s;
	uSrand(a,NUM);
	printf("随机产生的%d个随机数是：\n",NUM);
	uShow(a,NUM);
	printf("随机产生的%d个随机数的和是：\n",NUM);
	printf("%d\n",uSum(a,NUM));
	uSort(a,NUM);
    printf("\n");
	printf("使用uOperate返回sum和average:\n");
	s = uOperate(a,NUM);
	printf("sum=%d  average=%f\n",s.sum,s.average);
    printf("开始写入文件...\n");
	uWriteTo(a,NUM);
	printf("写入文件结束.\n");
	return 0;
}

void uSrand(int *a,int num){
	int i = 0;
	srand((int)time(0));
	for(i;i<num;i++){
		a[i] = 1+(int)(10.0*rand()/(RAND_MAX+1.0));
	}
}


int uSum(int *a,int num){
	int sum = 0;
	int i = 0;
	for(i;i<num;i++){
		sum += a[i];
	}
	return sum;
}


int uShow(int *a,int num){
	int i = 0;
	for(i;i<num;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}


int compar(const void *a,const void *b){
	int *aa = (int *)a,*bb = (int *)b;
	if(*aa>*bb) return 1;
	if(*aa==*bb) return 0;
	if(*aa<*bb) return -1;
}

void uSort(int *a,int num){
	int begin = 0;
	int end = 0;
	int i;
	begin = uGetTime();
	printf("排序前：\n");
	for(i=0;i<num;i++){
		printf("%d  ",a[i]);
	}
    printf("\n");
	printf("开始排序的时间：%d\n",begin);
	qsort(a,num,sizeof(int),compar);
	printf("排序的结果：\n");
	for(i=0;i<num;i++){
		printf("%d  ",a[i]);
	}
	printf("\n");
	end = uGetTime();
	printf("结束排序的时间：%d\n",end);
	printf("总用时：%d",end-begin);
}

int uGetTime(){
	time_t timep;
	time(&timep);
	return &timep;
}

float uAve(int *a,int num){
	int sum = uSum(a,num);
	float ave = (1.0*sum) /num;
	return ave;
}

struct Str uOperate(int *a,int num){
	int sum = uSum(a,num);
	float ave = uAve(a,num); 
	struct Str s1;
	s1.sum = sum;
	s1.average = ave;
	return s1;
}

void uWriteTo(int*a[],int num){
	int fd = open("/home/cy/cy_work/u",O_RDWR|O_CREAT,S_IRUSR|S_IWUSR);
	write(fd,a,num);
    close(fd);
}





















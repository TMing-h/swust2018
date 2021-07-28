#include<stdio.h>
#include<stdlib.h> 
#include<time.h>
int main(){
	int N,n,j;
	FILE *fp;
	printf("请输出需要产生的随机数个数n：");
	scanf("%d",&n);
	printf("请输入需要生成的随机数范围([0,N])：");
	scanf("%d",&N);
	int b[n];
	int c[n];
	printf("产生随机数如下：\n"); 
	for(int i = 0; i < n; i++){
		srand((unsigned)time(NULL)+rand());
		int a = rand()%N;
		printf("%d ",a);
		b[i] = a;
	}
	printf("\n");
	return 0;
}

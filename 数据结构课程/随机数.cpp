#include<stdio.h>
#include<stdlib.h> 
#include<time.h>
int main(){
	int N,n,j;
	FILE *fp;
	printf("�������Ҫ���������������n��");
	scanf("%d",&n);
	printf("��������Ҫ���ɵ��������Χ([0,N])��");
	scanf("%d",&N);
	int b[n];
	int c[n];
	printf("������������£�\n"); 
	for(int i = 0; i < n; i++){
		srand((unsigned)time(NULL)+rand());
		int a = rand()%N;
		printf("%d ",a);
		b[i] = a;
	}
	printf("\n");
	return 0;
}

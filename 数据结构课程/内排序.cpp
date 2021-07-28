#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<iostream>
#define MaxSize 100000
using namespace std;
typedef struct{
	long data[MaxSize];
	int length;
}SqList;
void InitList(SqList &L,long a[],int n){
	int i,k = 0;
	for(i = 0; i < n;i++){
		L.data[k] = a[i];
		k++;
	}
	L.length = k;
}
void InitHeap(SqList &D,long a[],int n){
	int i,k = 1;
	for(i = 0; i < n;i++){
		D.data[k] = a[i];
		k++;
	}
	D.length = k-1;
}
void Swap(long &a,long &b){
	long tmp = a;
	a = b;
	b = tmp;
}
void BubbleSort(SqList L,int &e,int &ee){
	int i,j;
	bool exchange;
	for(i = 0; i < L.length; i++){ 
		exchange = false;
		for(j = L.length-1; j > i; j--){ //从最后一个数据开始扫描
			if(L.data[j] < L.data[j-1]){//相邻的进行比较
				e++;
				Swap(L.data[j],L.data[j-1]);//小的向前移（上浮） 
				ee = ee + 3;
				exchange = true;
			}
			else
				e++;
		}
		if(!exchange)//若某趟排序没有发生数据交换，说明已完成排序，无需继续 
			return;
	}
	for(i = 0; i < L.length; i++){
		printf("%ld ",L.data[i]);
	}
	printf("\n\n");
}
void InsertSort(SqList L,int &a1,int &aa){
	int i,j;
	for(i = 1; i < L.length; i++){ //初始有序区下标从0开始
		if(L.data[i] < L.data[i-1]){ //i指向无序头，无序区从下标1开始
			long tmp = L.data[i];
			aa++;
			j = i - 1;//j初始指向有序区尾元素
			do{
				a1++;//比较并移动
				aa++;
				L.data[j+1] = L.data[j];//关键字大于tmp的向后移 
				j--;//j向前指
			}while(j >= 0 && L.data[j] > tmp);
			a1++;//比较 L.data[j] <= tmp 不移动 
			L.data[j+1] = tmp;
			aa++;
		}
		else
			a1++;//L.data[i] >= L.data[i-1] 比较，不移动 
	}
	for(i = 0; i < L.length; i++){
		printf("%ld ",L.data[i]);
	}
	printf("\n\n");
}
void SelectSort(SqList L,int &f,int &ff){
	int i,j,k;
	for(i = 0; i < L.length-1; i++){//初始无有序区，无序区从0开始
		k = i;//每轮排序以无序区首元素为准进行选择 
		for(j = i + 1; j < L.length; j++){ 
			if(L.data[j] < L.data[k]){//找到更小的元素则用k指向它 
				k = j;
				f++;
			}
			else
				f++;
		}
		if(k != i){//若无序区中最小值不是首元素则互换二者位置 
			Swap(L.data[k],L.data[i]);
			ff = ff + 3;
		}
		f++;
	}
	for(i = 0; i < L.length; i++){
		printf("%ld ",L.data[i]);
	}
	printf("\n\n");
}
int partition(SqList &L,int s,int t,int &c,int &cc){
	int i = s,j = t;//i指向序列开头,j指向序列尾 
	long tmp = L.data[i];//以首元素为基准 
	cc++;
	while(i < j){
		while(j > i && L.data[j] >= tmp){//从右往左扫描，比tmp大的放到i(左边) 
			j--;
			c++;
		}
		c++;
		L.data[i] = L.data[j];
		if(j != i)
			cc++;
		while(i < j && L.data[i] <= tmp){//从左往右扫描，比tmp小的放到j(右边） 
			i++;
			c++;
		}
		c++;
		L.data[j] = L.data[i];
		if(j != i)
			cc++;
	}
	L.data[i] = tmp;//把tmp(基准元素)归为 
	cc++;
	return i;//返回基准元素所在位置 
}
void QuickSort(SqList &K,int s,int t,int &c,int &cc){
	int i;
	if(s < t){//该部分元素至少2个才进行划分
		i = partition(K,s,t,c,cc);
		QuickSort(K,s,i-1,c,cc);
		QuickSort(K,i+1,t,c,cc);
	}
}
void ShellSort(SqList L,int &b,int &bb){
	int d = L.length / 2;//置初始增量 
	while(d > 0){//循环直至d为1，即所有元素在同一个组 
		int i,j;
		for(i = d; i < L.length; i++){//对每一个组分别采用直接插入排序 
			if(L.data[i] < L.data[i-d]){//相邻d个位置的为1组，进行比较 
				long tmp = L.data[i];
				bb++;
				j = i - d;
				while(j >= 0 && L.data[j] > tmp){
					b++;
					bb++;
					L.data[j+d] = L.data[j];
					j = j - d;
				}
				b++;
				L.data[j+d] = tmp;
				bb++;
			}
			else
				b++;
		}
		d = d / 2;//一轮结束后减少增量 
	}
	for(int i = 0; i < L.length; i++){
		printf("%ld ",L.data[i]);
	}
	printf("\n\n");
}
void sift(SqList &D,int low,int high,int &d,int &dd){
	int i = low,j = 2 * i;//i指向根节点，j指向根节点的左孩子 
	long tmp = D.data[i];//保存根节点 
	dd++;
	while(j <= high){
		if(j < high && D.data[j] < D.data[j+1]){//由于要构造大根堆，因此让j指向根节点较大的那个孩子 
			j++;
			d++;
		}
		if(D.data[j] > tmp){//如果该孩子比tmp大，则将其作为新的双亲节点 
			d++;
			D.data[i] = D.data[j];
			dd++;
			i = j;//i指向新根节点原位置 
			j = 2 * i;//j指向新根节点原先的左孩子 
		}
		else{//由于筛选是假设完全二叉树的左右子树已是大根堆， 
			d++;//因此若当前左右孩子中较大者小于等于tmp，则无需再进行筛选 
			break;
		}
	}
	D.data[i] = tmp;
	dd++;
}
void HeapSort(SqList D,int &d,int &dd){
	for(int i = D.length / 2; i > 0; i--)//构造大根堆
		sift(D,i,D.length,d,dd);
	for(int i = D.length; i >= 2; i--){
		Swap(D.data[1],D.data[i]);//完成交换
		dd = dd + 3;
		sift(D,1,i-1,d,dd);//利用剩余元素构造大根堆
	}
	for(int i = 1; i <= D.length; i++){
		printf("%ld ",D.data[i]);
	}
	printf("\n\n");
}
void RanDom(int n,int N,long b[]){
	for(int i = 0; i < n; i++){
		srand((unsigned)time(NULL)+rand());
		long a = rand()%N;
		printf("%ld ",a);
		b[i] = a;
	}
	printf("\n");
}
int main(){
	SqList L;
	SqList D;
	SqList K;
	char j,method;
	char n1[100] = "";
	int n,N;
	FILE *fp1,*fp2;
	while(1){
		int flag = 1;
		printf("请输入需要产生的随机数个数n(n不超过100000)\n");
		scanf("%s",n1);
		int len = strlen(n1);
		for(int i = 0; i < len; i++){
			if(n1[i] < '0' || n1[i] > '9'){
				flag = 0;
				break;
			}
		}
		if(flag == 0){
			printf("输入错误，重新输入！\n");
			continue;
		}
		else{
			n = atoi(n1);
			if(n <= 0 || n > 100000){
				printf("输入错误，重新输入！\n");
				continue;
			}
			else
				break;
		}
	}
	while(1){
		printf("请输入需要生成的随机数取值范围([0-N])(N不超过100000)：\n");
		scanf("%d",&N);
		if(N <= 0 || N > 100000){
			printf("输入错误，请重新输入！\n");
			continue; 
		}
		else
			break;
	}
	long b[n];
	long c[n];
	printf("产生随机数如下：\n");
	RanDom(n,N,b);
	if((fp1 = fopen("random.txt","r+"))== NULL){
		printf("数据保存失败！\n");
		exit(0);
	}
	for(int i = 0; i < n; i++){
		fprintf(fp1,"%ld ",b[i]);
	}
	rewind(fp1);
	printf("随机数已保存至文件。\n");
	printf("输入'1'读取随机数文件进行排序，输入'0'结束程序：\n");
	while(1){
		cin>>j;
		if(j != '1' && j != '0')
			printf("输入错误，重新输入！\n");
		else
			break;
	}
	if(j == '1'){
		for(int i = 0; i < n; i++){
			fscanf(fp1,"%ld ",&c[i]);
		}
		InitList(L,c,n);
		InitHeap(D,c,n);
		InitList(K,c,n);
		fclose(fp1);
	}
	else
		exit(0);
	printf("数据读取成功！\n");
	printf("输入'1'进入排序界面，输入'0'退出程序\n");
	while(1){
		cin>>j;
		if(j != '1' && j != '0')
			printf("输入错误，重新输入！\n");
		else
			break;
	}
	if(j == '0')
		exit(0);
	else{
		while(1){
		int a1=0,aa=0,b=0,bb=0,c=0,cc=0,d=0,dd=0,e=0,ee=0,f=0,ff=0;
		printf("***************************\n");
		printf("请选择需要的排序方法：\n");
		printf("1. 插入排序\n");//a
		printf("2. 希尔排序\n");//b
		printf("3. 快速排序\n");//c
		printf("4. 堆排序\n");//d
		printf("5. 冒泡排序\n");//e
		printf("6. 选择排序\n");//f
		printf("7. 以上所有排序方式\n");
		printf("8. 退出程序\n");
		printf("***************************\n\n");
		while(1){
			cin>>method;
			if(method < '1' || method > '8'){
				printf("输入错误，请重新输入！\n");
				continue;
			}
			else
				break;
		} 
		if((fp2 = fopen("output.txt","a")) == 0){
			printf("写入失败！\n");
			exit(0);
		}
		printf("*********************************************\n");
		switch(method){
			case '1':
				printf("插入排序结果：\n");
				fprintf(fp2,"%s","插入排序结果：\n");
				InsertSort(L,a1,aa);
				printf("关键字比较次数：%d     ",a1);
				fprintf(fp2,"%s：%d     ","关键字比较次数",a1);
				printf("关键字移动次数：%d\n",aa);
				fprintf(fp2,"%s：%d\n","关键字移动次数",aa);
				printf("*********************************************\n");
				break; 
			case '2':
				printf("希尔排序结果：\n");
				fprintf(fp2,"%s","希尔排序结果：\n");
				ShellSort(L,b,bb);
				printf("关键字比较次数：%d     ",b);
				fprintf(fp2,"%s：%d     ","关键字比较次数",b);
				printf("关键字移动次数：%d\n",bb);
				fprintf(fp2,"%s：%d\n","关键字移动次数",bb);
				printf("*********************************************\n");
				break;
			case '3':
				printf("快速排序结果：\n");
				fprintf(fp2,"%s","快速排序结果：\n");
				QuickSort(K,0,K.length-1,c,cc);
				for(int i = 0; i < K.length; i++){
					printf("%ld ",K.data[i]);
				}
				printf("\n\n");
				printf("关键字比较次数：%d     ",c);
				fprintf(fp2,"%s：%d     ","关键字比较次数",c);
				printf("关键字移动次数：%d\n",cc);
				fprintf(fp2,"%s：%d\n","关键字移动次数",cc);
				printf("*********************************************\n");
				break;
			case '4':
				printf("堆排序结果：\n");
				fprintf(fp2,"%s","堆排序结果：\n");
				HeapSort(D,d,dd);
				printf("关键字比较次数：%d     ",d);
				fprintf(fp2,"%s：%d     ","关键字比较次数",d);
				printf("关键字移动次数：%d\n",dd);
				fprintf(fp2,"%s：%d\n","关键字移动次数",dd);
				printf("*********************************************\n");
				break;
			case '5':
				printf("冒泡排序结果：\n");
				fprintf(fp2,"%s","冒泡排序结果：\n");
				BubbleSort(L,e,ee);
				printf("关键字比较次数：%d     ",e);
				fprintf(fp2,"%s：%d     ","关键字比较次数",e);
				printf("关键字移动次数：%d\n",ee);
				fprintf(fp2,"%s：%d\n","关键字移动次数",ee);
				printf("*********************************************\n");
				break;
			case '6':
				printf("选择排序结果：\n");
				fprintf(fp2,"%s","选择排序结果：\n");
				SelectSort(L,f,ff);
				printf("关键字比较次数：%d     ",f);
				fprintf(fp2,"%s：%d     ","关键字比较次数",f);
				printf("关键字移动次数：%d\n",ff);
				fprintf(fp2,"%s：%d\n","关键字移动次数",ff);
				printf("*********************************************\n");
				break;
			case '7':
				printf("插入排序结果：\n");
				fprintf(fp2,"%s","插入排序结果：\n");
				InsertSort(L,a1,aa);
				printf("关键字比较次数：%d     ",a1);
				fprintf(fp2,"%s：%d     ","关键字比较次数",a1);
				printf("关键字移动次数：%d\n\n",aa);
				fprintf(fp2,"%s：%d\n","关键字移动次数",aa);
				printf("希尔排序结果：\n");
				fprintf(fp2,"%s","希尔排序结果：\n");
				ShellSort(L,b,bb);
				printf("关键字比较次数：%d     ",b);
				fprintf(fp2,"%s：%d     ","关键字比较次数",b);
				printf("关键字移动次数：%d\n\n",bb);
				fprintf(fp2,"%s：%d\n","关键字移动次数",bb);
				printf("快速排序结果：\n");
				fprintf(fp2,"%s","快速排序结果：\n");
				QuickSort(K,0,K.length-1,c,cc);
				for(int i = 0; i < K.length; i++){
					printf("%ld ",K.data[i]);
				}
				printf("\n\n");
				printf("关键字比较次数：%d     ",c);
				fprintf(fp2,"%s：%d     ","关键字比较次数",c);
				printf("关键字移动次数：%d\n\n",cc);
				fprintf(fp2,"%s：%d\n","关键字移动次数",cc);
				printf("堆排序结果：\n");
				fprintf(fp2,"%s","堆排序结果：\n");
				HeapSort(D,d,dd);
				printf("关键字比较次数：%d     ",d);
				fprintf(fp2,"%s：%d     ","关键字比较次数",d);
				printf("关键字移动次数：%d\n\n",dd);
				fprintf(fp2,"%s：%d\n","关键字移动次数",dd);
				printf("冒泡排序结果：\n");
				fprintf(fp2,"%s","冒泡排序结果：\n");
				BubbleSort(L,e,ee);
				printf("关键字比较次数：%d     ",e);
				fprintf(fp2,"%s：%d     ","关键字比较次数",e);
				printf("关键字移动次数：%d\n\n",ee);
				fprintf(fp2,"%s：%d\n","关键字移动次数",ee);
				printf("选择排序结果：\n");
				fprintf(fp2,"%s","选择排序结果：\n");
				SelectSort(L,f,ff);
				printf("关键字比较次数：%d     ",f);
				fprintf(fp2,"%s：%d     ","关键字比较次数",f);
				printf("关键字移动次数：%d\n\n",ff);
				fprintf(fp2,"%s：%d\n","关键字移动次数",ff);
				printf("*********************************************\n");
				break;
			case '8':
				return 0;
			}
			printf("输入'1'继续，输入'0'退出\n");
			int flag;
			scanf("%d",&flag);
			if(flag)
				continue;
			else
				break;
		}
			fclose(fp2);
	}
	printf("程序结束...");
	return 0;
}

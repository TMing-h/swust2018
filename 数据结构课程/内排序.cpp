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
		for(j = L.length-1; j > i; j--){ //�����һ�����ݿ�ʼɨ��
			if(L.data[j] < L.data[j-1]){//���ڵĽ��бȽ�
				e++;
				Swap(L.data[j],L.data[j-1]);//С����ǰ�ƣ��ϸ��� 
				ee = ee + 3;
				exchange = true;
			}
			else
				e++;
		}
		if(!exchange)//��ĳ������û�з������ݽ�����˵������������������ 
			return;
	}
	for(i = 0; i < L.length; i++){
		printf("%ld ",L.data[i]);
	}
	printf("\n\n");
}
void InsertSort(SqList L,int &a1,int &aa){
	int i,j;
	for(i = 1; i < L.length; i++){ //��ʼ�������±��0��ʼ
		if(L.data[i] < L.data[i-1]){ //iָ������ͷ�����������±�1��ʼ
			long tmp = L.data[i];
			aa++;
			j = i - 1;//j��ʼָ��������βԪ��
			do{
				a1++;//�Ƚϲ��ƶ�
				aa++;
				L.data[j+1] = L.data[j];//�ؼ��ִ���tmp������� 
				j--;//j��ǰָ
			}while(j >= 0 && L.data[j] > tmp);
			a1++;//�Ƚ� L.data[j] <= tmp ���ƶ� 
			L.data[j+1] = tmp;
			aa++;
		}
		else
			a1++;//L.data[i] >= L.data[i-1] �Ƚϣ����ƶ� 
	}
	for(i = 0; i < L.length; i++){
		printf("%ld ",L.data[i]);
	}
	printf("\n\n");
}
void SelectSort(SqList L,int &f,int &ff){
	int i,j,k;
	for(i = 0; i < L.length-1; i++){//��ʼ������������������0��ʼ
		k = i;//ÿ����������������Ԫ��Ϊ׼����ѡ�� 
		for(j = i + 1; j < L.length; j++){ 
			if(L.data[j] < L.data[k]){//�ҵ���С��Ԫ������kָ���� 
				k = j;
				f++;
			}
			else
				f++;
		}
		if(k != i){//������������Сֵ������Ԫ���򻥻�����λ�� 
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
	int i = s,j = t;//iָ�����п�ͷ,jָ������β 
	long tmp = L.data[i];//����Ԫ��Ϊ��׼ 
	cc++;
	while(i < j){
		while(j > i && L.data[j] >= tmp){//��������ɨ�裬��tmp��ķŵ�i(���) 
			j--;
			c++;
		}
		c++;
		L.data[i] = L.data[j];
		if(j != i)
			cc++;
		while(i < j && L.data[i] <= tmp){//��������ɨ�裬��tmpС�ķŵ�j(�ұߣ� 
			i++;
			c++;
		}
		c++;
		L.data[j] = L.data[i];
		if(j != i)
			cc++;
	}
	L.data[i] = tmp;//��tmp(��׼Ԫ��)��Ϊ 
	cc++;
	return i;//���ػ�׼Ԫ������λ�� 
}
void QuickSort(SqList &K,int s,int t,int &c,int &cc){
	int i;
	if(s < t){//�ò���Ԫ������2���Ž��л���
		i = partition(K,s,t,c,cc);
		QuickSort(K,s,i-1,c,cc);
		QuickSort(K,i+1,t,c,cc);
	}
}
void ShellSort(SqList L,int &b,int &bb){
	int d = L.length / 2;//�ó�ʼ���� 
	while(d > 0){//ѭ��ֱ��dΪ1��������Ԫ����ͬһ���� 
		int i,j;
		for(i = d; i < L.length; i++){//��ÿһ����ֱ����ֱ�Ӳ������� 
			if(L.data[i] < L.data[i-d]){//����d��λ�õ�Ϊ1�飬���бȽ� 
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
		d = d / 2;//һ�ֽ������������ 
	}
	for(int i = 0; i < L.length; i++){
		printf("%ld ",L.data[i]);
	}
	printf("\n\n");
}
void sift(SqList &D,int low,int high,int &d,int &dd){
	int i = low,j = 2 * i;//iָ����ڵ㣬jָ����ڵ������ 
	long tmp = D.data[i];//������ڵ� 
	dd++;
	while(j <= high){
		if(j < high && D.data[j] < D.data[j+1]){//����Ҫ�������ѣ������jָ����ڵ�ϴ���Ǹ����� 
			j++;
			d++;
		}
		if(D.data[j] > tmp){//����ú��ӱ�tmp��������Ϊ�µ�˫�׽ڵ� 
			d++;
			D.data[i] = D.data[j];
			dd++;
			i = j;//iָ���¸��ڵ�ԭλ�� 
			j = 2 * i;//jָ���¸��ڵ�ԭ�ȵ����� 
		}
		else{//����ɸѡ�Ǽ�����ȫ�������������������Ǵ���ѣ� 
			d++;//�������ǰ���Һ����нϴ���С�ڵ���tmp���������ٽ���ɸѡ 
			break;
		}
	}
	D.data[i] = tmp;
	dd++;
}
void HeapSort(SqList D,int &d,int &dd){
	for(int i = D.length / 2; i > 0; i--)//��������
		sift(D,i,D.length,d,dd);
	for(int i = D.length; i >= 2; i--){
		Swap(D.data[1],D.data[i]);//��ɽ���
		dd = dd + 3;
		sift(D,1,i-1,d,dd);//����ʣ��Ԫ�ع�������
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
		printf("��������Ҫ���������������n(n������100000)\n");
		scanf("%s",n1);
		int len = strlen(n1);
		for(int i = 0; i < len; i++){
			if(n1[i] < '0' || n1[i] > '9'){
				flag = 0;
				break;
			}
		}
		if(flag == 0){
			printf("��������������룡\n");
			continue;
		}
		else{
			n = atoi(n1);
			if(n <= 0 || n > 100000){
				printf("��������������룡\n");
				continue;
			}
			else
				break;
		}
	}
	while(1){
		printf("��������Ҫ���ɵ������ȡֵ��Χ([0-N])(N������100000)��\n");
		scanf("%d",&N);
		if(N <= 0 || N > 100000){
			printf("����������������룡\n");
			continue; 
		}
		else
			break;
	}
	long b[n];
	long c[n];
	printf("������������£�\n");
	RanDom(n,N,b);
	if((fp1 = fopen("random.txt","r+"))== NULL){
		printf("���ݱ���ʧ�ܣ�\n");
		exit(0);
	}
	for(int i = 0; i < n; i++){
		fprintf(fp1,"%ld ",b[i]);
	}
	rewind(fp1);
	printf("������ѱ������ļ���\n");
	printf("����'1'��ȡ������ļ�������������'0'��������\n");
	while(1){
		cin>>j;
		if(j != '1' && j != '0')
			printf("��������������룡\n");
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
	printf("���ݶ�ȡ�ɹ���\n");
	printf("����'1'����������棬����'0'�˳�����\n");
	while(1){
		cin>>j;
		if(j != '1' && j != '0')
			printf("��������������룡\n");
		else
			break;
	}
	if(j == '0')
		exit(0);
	else{
		while(1){
		int a1=0,aa=0,b=0,bb=0,c=0,cc=0,d=0,dd=0,e=0,ee=0,f=0,ff=0;
		printf("***************************\n");
		printf("��ѡ����Ҫ�����򷽷���\n");
		printf("1. ��������\n");//a
		printf("2. ϣ������\n");//b
		printf("3. ��������\n");//c
		printf("4. ������\n");//d
		printf("5. ð������\n");//e
		printf("6. ѡ������\n");//f
		printf("7. ������������ʽ\n");
		printf("8. �˳�����\n");
		printf("***************************\n\n");
		while(1){
			cin>>method;
			if(method < '1' || method > '8'){
				printf("����������������룡\n");
				continue;
			}
			else
				break;
		} 
		if((fp2 = fopen("output.txt","a")) == 0){
			printf("д��ʧ�ܣ�\n");
			exit(0);
		}
		printf("*********************************************\n");
		switch(method){
			case '1':
				printf("������������\n");
				fprintf(fp2,"%s","������������\n");
				InsertSort(L,a1,aa);
				printf("�ؼ��ֱȽϴ�����%d     ",a1);
				fprintf(fp2,"%s��%d     ","�ؼ��ֱȽϴ���",a1);
				printf("�ؼ����ƶ�������%d\n",aa);
				fprintf(fp2,"%s��%d\n","�ؼ����ƶ�����",aa);
				printf("*********************************************\n");
				break; 
			case '2':
				printf("ϣ����������\n");
				fprintf(fp2,"%s","ϣ����������\n");
				ShellSort(L,b,bb);
				printf("�ؼ��ֱȽϴ�����%d     ",b);
				fprintf(fp2,"%s��%d     ","�ؼ��ֱȽϴ���",b);
				printf("�ؼ����ƶ�������%d\n",bb);
				fprintf(fp2,"%s��%d\n","�ؼ����ƶ�����",bb);
				printf("*********************************************\n");
				break;
			case '3':
				printf("������������\n");
				fprintf(fp2,"%s","������������\n");
				QuickSort(K,0,K.length-1,c,cc);
				for(int i = 0; i < K.length; i++){
					printf("%ld ",K.data[i]);
				}
				printf("\n\n");
				printf("�ؼ��ֱȽϴ�����%d     ",c);
				fprintf(fp2,"%s��%d     ","�ؼ��ֱȽϴ���",c);
				printf("�ؼ����ƶ�������%d\n",cc);
				fprintf(fp2,"%s��%d\n","�ؼ����ƶ�����",cc);
				printf("*********************************************\n");
				break;
			case '4':
				printf("����������\n");
				fprintf(fp2,"%s","����������\n");
				HeapSort(D,d,dd);
				printf("�ؼ��ֱȽϴ�����%d     ",d);
				fprintf(fp2,"%s��%d     ","�ؼ��ֱȽϴ���",d);
				printf("�ؼ����ƶ�������%d\n",dd);
				fprintf(fp2,"%s��%d\n","�ؼ����ƶ�����",dd);
				printf("*********************************************\n");
				break;
			case '5':
				printf("ð����������\n");
				fprintf(fp2,"%s","ð����������\n");
				BubbleSort(L,e,ee);
				printf("�ؼ��ֱȽϴ�����%d     ",e);
				fprintf(fp2,"%s��%d     ","�ؼ��ֱȽϴ���",e);
				printf("�ؼ����ƶ�������%d\n",ee);
				fprintf(fp2,"%s��%d\n","�ؼ����ƶ�����",ee);
				printf("*********************************************\n");
				break;
			case '6':
				printf("ѡ����������\n");
				fprintf(fp2,"%s","ѡ����������\n");
				SelectSort(L,f,ff);
				printf("�ؼ��ֱȽϴ�����%d     ",f);
				fprintf(fp2,"%s��%d     ","�ؼ��ֱȽϴ���",f);
				printf("�ؼ����ƶ�������%d\n",ff);
				fprintf(fp2,"%s��%d\n","�ؼ����ƶ�����",ff);
				printf("*********************************************\n");
				break;
			case '7':
				printf("������������\n");
				fprintf(fp2,"%s","������������\n");
				InsertSort(L,a1,aa);
				printf("�ؼ��ֱȽϴ�����%d     ",a1);
				fprintf(fp2,"%s��%d     ","�ؼ��ֱȽϴ���",a1);
				printf("�ؼ����ƶ�������%d\n\n",aa);
				fprintf(fp2,"%s��%d\n","�ؼ����ƶ�����",aa);
				printf("ϣ����������\n");
				fprintf(fp2,"%s","ϣ����������\n");
				ShellSort(L,b,bb);
				printf("�ؼ��ֱȽϴ�����%d     ",b);
				fprintf(fp2,"%s��%d     ","�ؼ��ֱȽϴ���",b);
				printf("�ؼ����ƶ�������%d\n\n",bb);
				fprintf(fp2,"%s��%d\n","�ؼ����ƶ�����",bb);
				printf("������������\n");
				fprintf(fp2,"%s","������������\n");
				QuickSort(K,0,K.length-1,c,cc);
				for(int i = 0; i < K.length; i++){
					printf("%ld ",K.data[i]);
				}
				printf("\n\n");
				printf("�ؼ��ֱȽϴ�����%d     ",c);
				fprintf(fp2,"%s��%d     ","�ؼ��ֱȽϴ���",c);
				printf("�ؼ����ƶ�������%d\n\n",cc);
				fprintf(fp2,"%s��%d\n","�ؼ����ƶ�����",cc);
				printf("����������\n");
				fprintf(fp2,"%s","����������\n");
				HeapSort(D,d,dd);
				printf("�ؼ��ֱȽϴ�����%d     ",d);
				fprintf(fp2,"%s��%d     ","�ؼ��ֱȽϴ���",d);
				printf("�ؼ����ƶ�������%d\n\n",dd);
				fprintf(fp2,"%s��%d\n","�ؼ����ƶ�����",dd);
				printf("ð����������\n");
				fprintf(fp2,"%s","ð����������\n");
				BubbleSort(L,e,ee);
				printf("�ؼ��ֱȽϴ�����%d     ",e);
				fprintf(fp2,"%s��%d     ","�ؼ��ֱȽϴ���",e);
				printf("�ؼ����ƶ�������%d\n\n",ee);
				fprintf(fp2,"%s��%d\n","�ؼ����ƶ�����",ee);
				printf("ѡ����������\n");
				fprintf(fp2,"%s","ѡ����������\n");
				SelectSort(L,f,ff);
				printf("�ؼ��ֱȽϴ�����%d     ",f);
				fprintf(fp2,"%s��%d     ","�ؼ��ֱȽϴ���",f);
				printf("�ؼ����ƶ�������%d\n\n",ff);
				fprintf(fp2,"%s��%d\n","�ؼ����ƶ�����",ff);
				printf("*********************************************\n");
				break;
			case '8':
				return 0;
			}
			printf("����'1'����������'0'�˳�\n");
			int flag;
			scanf("%d",&flag);
			if(flag)
				continue;
			else
				break;
		}
			fclose(fp2);
	}
	printf("�������...");
	return 0;
}

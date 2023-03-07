#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include <math.h>
void crease_1(int v[],int N,int t);
void crease_2(int v[],int N);
void output(double v[],double u[],int N);
void scale(int v[],double g[],int N);//��������Ҫ�ĺ��� 
int m=2147483647;
int a=16807;
int q=floor(m/a);
int r=m%a;
int temp;//����ȫ�ֱ��� 
int main()
{
	int *pb_1;
	int *pb_2;
	double *p_1;
	double *p_2;
	int N,t;
	printf("q=%d\n",q);
    printf("r=%d\nPlease Input the Number:",r);
	scanf("%d",&N);
	printf("Number is %d\nPlease Input the Seed",N);
	scanf("%d",&t);
	printf("The seed is %d\n",t);
	pb_1=(int *)malloc(N*sizeof(int));
	pb_2=(int *)malloc(N*sizeof(int));
	p_1=(double *)malloc(N*sizeof(double));
	p_2=(double *)malloc(N*sizeof(double));//���䶯̬�ռ� 
	crease_1(pb_1,N,t);
    crease_2(pb_2,N);//������������������� 
	scale(pb_1,p_1,N);
	scale(pb_2,p_2,N);//�ı����䣬���ı���ֵ���� 
	output(p_1,p_2,N);//���ļ������ 
	free(pb_1);
	free(pb_2);
	free(p_1);
	free(p_2);//�ͷ��ڴ� 
 }
 void crease_1(int v[],int N,int t)//�������ɺ��� 
 {
 	v[0]=t;//�������� 
 	for(int i=0;i<=N;i++)
	{
		if(a*(v[i]%q)-r*floor(v[i]/q)>=0)
		v[i+1]=a*(v[i]%q)-r*floor(v[i]/q);
		else 
		v[i+1]=a*(v[i]%q)-r*floor(v[i]/q)+m;
	}
	temp=v[N];//�µ����� 
 }
 void crease_2(int v[],int N)//�������ɺ��� 
 {
 	v[N+1]=temp;//�������� 
 	for(int i=N+1;i>=0;i--)
	{
		if(a*(v[i]%q)-r*floor(v[i]/q)>=0)
		v[i-1]=a*(v[i]%q)-r*floor(v[i]/q);
		else 
		v[i-1]=a*(v[i]%q)-r*floor(v[i]/q)+m;
	}
 }
 void output(double v[],double u[],int N)//������� 
 {
 	FILE *fp;
	fp=fopen("test.dat","w");
	if(fp==NULL) 
	{
		printf("false");
	}
	for(int i=1;i<=N;i++)
	{
		fprintf(fp,"%lf %lf\n",v[i],u[i]);
	}
	fclose(fp);
 }
 void scale(int v[],double g[],int N)//rescale ���� 
 {
 	for(int i=1;i<=N;i++)
 	{
		g[i]=(double)v[i]/m;
	}
 }

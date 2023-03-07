#include<iostream>
#include<math.h>
#include<stdlib.h>
void read(double v[],double u[],int N);
double cor(double v[],int N,int K);
double cor_2(double v[],int N,int l);//�������� 
int main()
{
	int N; 
	printf("Please input the number:");
	scanf("%d",&N);
	printf("The number of data is %d\nPlease input the order:",N);
	int K;
	scanf("%d",&K);
	printf("The order is %d\nPlease input the step gap:",K);
	int l;
	scanf("%d",&l);
	printf("The step gap is %d\nNow begin to calculate, please wait...\n",l);
	double *p_1;
	double *p_2;
	p_1=(double *)malloc(N*sizeof(double));
	p_2=(double *)malloc(N*sizeof(double));//���䶯̬�ڴ�ռ� 
	read(p_1,p_2,N);//���ļ��ж�ȡ���� 
	double u=cor(p_1,N,K);// ����߽׾� 
	double dif=(u-(double)1/(K+1));//������� 
	printf("dif=%lf\n",dif);//��� 
	printf("dif=%lf\n",dif*sqrt(N));//�����N��ϵ�ĳ��� 
	u=cor(p_1,N,1);
	double C_l=(cor_2(p_1,N,l)-u*u)/(cor(p_1,N,2)-u*u);//��������غ��� 
	printf("The C_l is %lf\n",C_l);
	FILE *fq;
	fq=fopen("c-dif-2.dat","w");
	/*for(int i=1;i<=10;i++)
	{*/
	int i=2;
		for(int j=1;j<=199;j++)
		{
			fprintf(fq,"%d %d %lf\n",i,j*100000,(cor(p_1,j*100000,i)-(double)1/(i+1))*sqrt(j*100000));
		}
	/*}*/
	fclose(fq);
	free(p_1);
	free(p_2);
} 
void read(double v[],double u[],int N)//��ȡ���� 
{
	FILE *fp;
	fp=fopen("test.dat","r+");
	if(fp==NULL)
	{
		printf("NULL"); 
	}
	for(int i=1;i<=N;i++)
	{
		fscanf (fp,"%lf",&v[i]);
		fscanf (fp,"%lf",&u[i]);
	}

	fclose(fp);
}
double cor(double v[],int N,int K)///����� 
{
	double M=0;
	for(int i=1;i<=N;i++)
	{
		v[i]=pow(v[i],(double)K);
		M+=v[i]/(double)N;
	}
	return(M);
}
double cor_2(double v[],int N,int l)//�������ⲽ���ľ� 
{
    double M=0;
	for(int i=1;i<=N;i++)
	{
		M+=v[i]*v[i+l]/(double)N;
	}
	return(M);
} 
void output(double v[],double u[],int N)//������� 
 {
 	FILE *fp;
	fp=fopen("N-dif.dat","w");
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

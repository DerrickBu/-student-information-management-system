#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")






struct person
{
	int num;
	char name[30];
	float grade[6];
	float zong;
	float pingjun0;
	int ranking;
	struct person *next;
}student[30];
struct person student0[30];
char filename1[30];
char filename[30];









struct person *creat(struct person *h,int n,int j)//���ļ�������Ϣ����������
{
	struct person *h;//����ͷ���
	h=wenjianduru1();
	struct person *p,*q;
	int m,i,k;//����ѭ������
	FILE *fp;
	printf("������Ҫ����Ϣ���浽���ļ�������β��Ϊ.txt��\n");
	scanf("%s",filename1);
	if((fp=fopen(filename1,"w"))==NULL)
		printf("can not open the file!\n");
	h=q=(struct person *)malloc(sizeof(struct person));
	printf("�������1���˵���Ϣ:ѧ�� ����������ֻ֧��Ӣ�����룩 ");
	for(k=1;k<=j;k++)
        printf("��%d�Ƴɼ� ",k);
    printf("\n");
	scanf("%d",&(h->num));
	fprintf(fp,"%3d",h->num);
	scanf("%s",h->name);
	fprintf(fp,"%s",h->name);
	for(m=0;m<j;m++)
	{
		scanf("%f",&(h->grade[m]));
		fprintf(fp,"%3f",h->grade[m]);
	}
	fprintf(fp,"\n");
	for(i=2;i<=n;i++)
	{
		p=(struct person *)malloc(sizeof(struct person));
		printf("�������%d���˵���Ϣ:ѧ�� ���� ",i);
		for(k=1;k<=j;k++)
            printf("��%d�Ƴɼ� ",k);
		printf("\n");
		scanf("%d",&(p->num));
		fprintf(fp,"%3d",p->num);
		scanf("%s",p->name);
		fprintf(fp,"%s",p->name);
	    for(m=0;m<j;m++)
		{
			scanf("%f",&(p->grade[m]));
			fprintf(fp,"%3f",p->grade[m]);
		}
		fprintf(fp,"\n");
		q->next=p;
		q=p;
	}
	q->next=NULL;
	fclose(fp);
	printf("Successfully input %d students\n",n);
	return h;
}







bool jiancha(struct person *h,int n,int j)
{
	struct person *p;
	int u,i;
	int t,s;
	p=h;
	for(i=0;i<n;i++)
	{
		student[i].num=p->num;
		strcpy(student[i].name,p->name);
		student[i].zong=p->zong;
		student[i].pingjun0=p->pingjun0;
		for(u=0;u<j;u++)
			student[i].grade[u]=p->grade[u];
		p=p->next;
	}
	for(t=0;t<n;t++)
	{
		for(s=0;s<t;s++)
		{
			if(student[t].num==student[s].num)
			{
				printf("ѧ�������ظ�,����������\n");
				return 0;
			}
		}
	}
	return 1;
}


























void kechengtongji(struct person *h,int n,int j)//���ÿ��ƽ���ɼ����ܳɼ�
{
	int p;
	struct person *o;
	float sum=0,pingjun;
	o=h;
	for(p=0;p<j;p++)
	{
		while(o!=NULL)
		{
			sum+=o->grade[p];
			o=o->next;
		}
		pingjun=sum/j;
		printf("��%d�Ƶ��ܳɼ�Ϊ%f\n",p+1,sum);
		printf("��%d�Ƶ�ƽ���ɼ�Ϊ%f\n",p+1,pingjun);
		sum=0;
		o=h;
	}
}

















void gerentongji(struct person *h,int n,int j)//������˸��Ƴɼ����ܳɼ�
{
	int p,q=1;
	struct person *o;
	float sum=0,pingjun;
	o=h;
	while(o!=NULL)
	{
		for(p=0;p<j;p++)
			sum+=o->grade[p];
		pingjun=sum/j;
		o->zong=sum;
		o->pingjun0=pingjun;
		printf("��%d���˵��ܳɼ�Ϊ%f\n",q,sum);
		printf("��%d���˵�ƽ���ɼ�Ϊ%f\n",q,pingjun);
		q++;
		sum=0;
		o=o->next;
	}
}














void sortdown(struct person *h,int n,int j)//�Ӹߵ������ѧ���ܷ�
{
	struct person *p,*o;
	int u,i,v,d;
	int t,s;
	float sum=0,pingjun;
	float temp;//�����м����
	int temp0;
	char name0[30];
	p=h;
	o=h;
	while(o!=NULL)
	{
		for(d=0;d<j;d++)
			sum+=o->grade[d];
		pingjun=sum/j;
		o->zong=sum;
		o->pingjun0=pingjun;
		sum=0;
		o=o->next;
	}
	for(i=0;i<n;i++)
	{
		student[i].num=p->num;
		strcpy(student[i].name,p->name);
		student[i].zong=p->zong;
		student[i].pingjun0=p->pingjun0;
		for(u=0;u<j;u++)
			student[i].grade[u]=p->grade[u];
		p=p->next;
	}
	for(t=0;t<n-1;t++)
	{
		for(s=0;s<n-1-t;s++)
		{
			if(student[s].zong<student[s+1].zong)
			{
				temp=student[s].zong;
				student[s].zong=student[s+1].zong;
				student[s+1].zong=temp;
				temp0=student[s].num;
				student[s].num=student[s+1].num;
				student[s+1].num=temp0;
				strcpy(name0,student[s].name);
				strcpy(student[s].name,student[s+1].name);
				strcpy(student[s+1].name,name0);
				for(i=0;i<j;i++)
                {
                    temp=student[s].grade[i];
                    student[s].grade[i]=student[s+1].grade[i];
                    student[s+1].grade[i]=temp;
                }
			}
		}
	}
	printf("�����Ӹߵ���ѧ������Ϊ��\n");
	for(v=0;v<n;v++)
    {
        printf("%d %s %d %f ",v+1,student[v].name,student[v].num,student[v].zong);
        for(i=0;i<j;i++)
            printf("%f ",student[v].grade[i]);
        printf("\n");
        student[v].ranking=v+1;
    }
}














void sortup(struct person *h,int n,int j)//�ӵ͵������ѧ���ܷ�
{
	struct person *p,*o;
	int u,i,v;
	int t,s,d;
	float sum=0,pingjun;
	float temp;//�����м����
	int temp0;
	char name0[30];
	p=h;
	o=h;
	while(o!=NULL)
	{
		for(d=0;d<j;d++)
			sum+=o->grade[d];
		pingjun=sum/j;
		o->zong=sum;
		o->pingjun0=pingjun;
		sum=0;
		o=o->next;
	}
	for(i=0;i<n;i++)
	{
		student[i].num=p->num;
		strcpy(student[i].name,p->name);
		student[i].zong=p->zong;
		student[i].pingjun0=p->pingjun0;
		for(u=0;u<j;u++)
			student[i].grade[u]=p->grade[u];
		p=p->next;
	}
	for(t=0;t<n-1;t++)
	{
		for(s=0;s<n-1-t;s++)
		{
			if(student[s].zong>student[s+1].zong)
			{
				temp=student[s].zong;
				student[s].zong=student[s+1].zong;
				student[s+1].zong=temp;
				temp0=student[s].num;
				student[s].num=student[s+1].num;
				student[s+1].num=temp0;
				strcpy(name0,student[s].name);
				strcpy(student[s].name,student[s+1].name);
				strcpy(student[s+1].name,name0);
				for(i=0;i<j;i++)
                {
                    temp=student[s].grade[i];
                    student[s].grade[i]=student[s+1].grade[i];
                    student[s+1].grade[i]=temp;
                }
			}
		}
	}
	printf("�����ӵ͵���ѧ������Ϊ��\n");
	for(v=0;v<n;v++)
    {
        printf("%d %s %d %f ",n-v,student[v].name,student[v].num,student[v].zong);
        for(i=0;i<j;i++)
            printf("%f ",student[v].grade[i]);
        printf("\n");
		student[v].ranking=n-v;
    }
}












void numsort(struct person *h,int n,int j)//��ѧ����С��������
{
    struct person *p,*o;
	int u,i,v;
	int t,s,d;
	float sum=0,pingjun;
	float temp;//�����м����
	int temp0;
	char name0[30];
	p=h;
	o=h;
	while(o!=NULL)
	{
		for(d=0;d<j;d++)
			sum+=o->grade[d];
		pingjun=sum/j;
		o->zong=sum;
		o->pingjun0=pingjun;
		sum=0;
		o=o->next;
	}
	for(i=0;i<n;i++)
	{
		student[i].num=p->num;
		strcpy(student[i].name,p->name);
		student[i].zong=p->zong;
		student[i].pingjun0=p->pingjun0;
		for(u=0;u<j;u++)
			student[i].grade[u]=p->grade[u];
		p=p->next;
	}
	for(t=0;t<n-1;t++)
	{
		for(s=0;s<n-1-t;s++)
		{
			if(student[s].num>student[s+1].num)
			{
				temp=student[s].zong;
				student[s].zong=student[s+1].zong;
				student[s+1].zong=temp;
				temp0=student[s].num;
				student[s].num=student[s+1].num;
				student[s+1].num=temp0;
				strcpy(name0,student[s].name);
				strcpy(student[s].name,student[s+1].name);
				strcpy(student[s+1].name,name0);
				for(i=0;i<j;i++)
                {
                    temp=student[s].grade[i];
                    student[s].grade[i]=student[s+1].grade[i];
                    student[s+1].grade[i]=temp;
                }
			}
		}
	}
	printf("��ѧ�Ŵ�С��������ѧ����ϢΪ��\n");
	for(v=0;v<n;v++)
    {
        printf("%s %d %f ",student[v].name,student[v].num,student[v].zong);
        for(i=0;i<j;i++)
            printf("%f ",student[v].grade[i]);
        printf("\n");
    }
}





















void namesort(struct person *h,int n,int j)//�������ֵ�˳������
{
    struct person *p,*o;
	int u,i,v;
	int t,s,d;
	float pingjun,sum=0;
	float temp;//�����м����
	int temp0;
	char name0[30];
	p=h;
	o=h;
	while(o!=NULL)
	{
		for(d=0;d<j;d++)
			sum+=o->grade[d];
		pingjun=sum/j;
		o->zong=sum;
		o->pingjun0=pingjun;
		sum=0;
		o=o->next;
	}
	for(i=0;i<n;i++)
	{
		student[i].num=p->num;
		strcpy(student[i].name,p->name);
		student[i].zong=p->zong;
		student[i].pingjun0=p->pingjun0;
		for(u=0;u<j;u++)
			student[i].grade[u]=p->grade[u];
		p=p->next;
	}
	for(t=0;t<n-1;t++)
	{
		for(s=0;s<n-1-t;s++)
		{
			if((strcmp(student[s].name,student[s+1].name))>0)
			{
				temp=student[s].zong;
				student[s].zong=student[s+1].zong;
				student[s+1].zong=temp;
				temp0=student[s].num;
				student[s].num=student[s+1].num;
				student[s+1].num=temp0;
				strcpy(name0,student[s].name);
				strcpy(student[s].name,student[s+1].name);
				strcpy(student[s+1].name,name0);
				for(i=0;i<j;i++)
                {
                    temp=student[s].grade[i];
                    student[s].grade[i]=student[s+1].grade[i];
                    student[s+1].grade[i]=temp;
                }
			}
		}
	}
	printf("�������ֵ�˳������ѧ����ϢΪ��\n");
	for(v=0;v<n;v++)
    {
        printf("%s %d %f ",student[v].name,student[v].num,student[v].zong);
        for(i=0;i<j;i++)
            printf("%f ",student[v].grade[i]);
        printf("\n");
    }
}


















void namesearch(struct person *h,int n,int j)//����������
{
	struct person *p;
	int u,i,v;
	int t,s,k=0;
	char c;
	float temp;//�����м����
	int temp0;
	char name0[30],name1[30];
	p=h;
	for(i=0;i<n;i++)
	{
		student[i].num=p->num;
		strcpy(student[i].name,p->name);
		student[i].zong=p->zong;
		student[i].pingjun0=p->pingjun0;
		for(u=0;u<j;u++)
			student[i].grade[u]=p->grade[u];
		p=p->next;
	}
	for(t=0;t<n-1;t++)
	{
		for(s=0;s<n-1-t;s++)
		{
			if(student[s].zong>student[s+1].zong)
			{
				temp=student[s].zong;
				student[s].zong=student[s+1].zong;
				student[s+1].zong=temp;
				temp0=student[s].num;
				student[s].num=student[s+1].num;
				student[s+1].num=temp0;
				strcpy(name0,student[s].name);
				strcpy(student[s].name,student[s+1].name);
				strcpy(student[s+1].name,name0);
				for(i=0;i<j;i++)
                {
                    temp=student[s].grade[i];
                    student[s].grade[i]=student[s+1].grade[i];
                    student[s+1].grade[i]=temp;
                }
			}
		}
	}
	for(v=0;v<n;v++)
       student[v].ranking=n-v;
	printf("��������Ҫ��ѯ��ѧ��������\n");
	scanf("%s",name1);
	c=getchar();
	for(i=0;i<n;i++)
	{
		if((strcmp(name1,student[i].name))==0)
			k++;
	}
	while(k==0)
	{
		printf("δ�ҵ���ѧ����Ϣ,����������\n");
		printf("��������Ҫ��ѯ��ѧ��������\n");
		scanf("%s",name1);
		c=getchar();
		for(i=0;i<n;i++)
		{
			if((strcmp(name1,student[i].name))==0)
				k++;
		}
	}
	for(i=0;i<n;i++)
    {
        if((strcmp(student[i].name,name1))==0)
        {
            printf("%d %s %d ",student[i].ranking,student[i].name,student[i].num);
            for(u=0;u<j;u++)
                printf("%f ",student[i].grade[u]);
            printf("\n");
        }
    }
}















void numsearch(struct person *h,int n,int j)//��ѧ�Ų���
{
	struct person *p;
	int u,i,v;
	int t,s,d,k=0;
	float temp;//�����м����
	int temp0;
	char name0[30];
	p=h;
	for(i=0;i<n;i++)
	{
		student[i].num=p->num;
		strcpy(student[i].name,p->name);
		student[i].zong=p->zong;
		student[i].pingjun0=p->pingjun0;
		for(u=0;u<j;u++)
			student[i].grade[u]=p->grade[u];
		p=p->next;
	}
	for(t=0;t<n-1;t++)
	{
		for(s=0;s<n-1-t;s++)
		{
			if(student[s].zong>student[s+1].zong)
			{
				temp=student[s].zong;
				student[s].zong=student[s+1].zong;
				student[s+1].zong=temp;
				temp0=student[s].num;
				student[s].num=student[s+1].num;
				student[s+1].num=temp0;
				strcpy(name0,student[s].name);
				strcpy(student[s].name,student[s+1].name);
				strcpy(student[s+1].name,name0);
				for(i=0;i<j;i++)
                {
                    temp=student[s].grade[i];
                    student[s].grade[i]=student[s+1].grade[i];
                    student[s+1].grade[i]=temp;
                }
			}
		}
	}
	for(v=0;v<n;v++)
       student[v].ranking=n-v;
	printf("��������Ҫ��ѯ��ѧ��ѧ�ţ�\n");
	scanf("%d",&d);
	for(i=0;i<n;i++)
	{
		if(d==student[i].num)
			k++;
	}
	while(k==0)
	{
		printf("δ�ҵ���ѧ����Ϣ,����������\n");
		printf("��������Ҫ��ѯ��ѧ��ѧ�ţ�\n");
		scanf("%d",&d);
		for(i=0;i<n;i++)
		{
			if(d==student[i].num)
				k++;
		}
	}
	for(i=0;i<n;i++)
    {
        if(student[i].num==d)
        {
            printf("%d %s %d ",student[i].ranking,student[i].name,student[i].num);
            for(u=0;u<j;u++)
                printf("%f ",student[i].grade[u]);
            printf("\n");
        }
    }
}














void print(struct person *h,int n,int j)//��ѧ����Ϣ�������ʾ��
{
	int p,q=1;
	struct person *o;
	float sum=0,pingjun;
	o=h;
	while(o!=NULL)
	{
		for(p=0;p<j;p++)
			sum+=o->grade[p];
		pingjun=sum/j;
		o->zong=sum;
		o->pingjun0=pingjun;
		q++;
		sum=0;
		o=o->next;
	}
	o=h;
	while(o!=NULL)
	{
		printf("%d %s %f %f ",o->num,o->name,o->zong,o->pingjun0);
		for(p=0;p<j;p++)
			printf("%f ",o->grade[p]);
		printf("\n");
		o=o->next;
	}
}

















void percent(struct person *h,int n,int j)//ͳ��ÿ�������������ٷֱ�
{
	struct person *p;
	int u,i;
	int t,s;
	float leibie[6][5];
	float baifenbi[6][5];
	char name4[30];
	FILE *fp;
	printf("�������ļ�������β��Ϊ.txt��\n");
	scanf("%s",name4);
	if((fp=fopen(name4,"w"))==NULL)
		printf("can not open the file!\n");
	p=h;
	for(i=0;i<j;i++)
	{
		for(t=0;t<5;t++)
			leibie[i][t]=0;
	}
	for(i=0;i<j;i++)
	{
		for(t=0;t<5;t++)
			baifenbi[i][t]=0;
	}
	for(i=0;i<n;i++)
	{
		student[i].num=p->num;
		strcpy(student[i].name,p->name);
		for(u=0;u<j;u++)
			student[i].grade[u]=p->grade[u];
		p=p->next;
	}
	for(t=0;t<j;t++)
	{
		for(s=0;s<n;s++)
		{
			if((student[s].grade[t]>=90)&&(student[s].grade[t]<=100))
				leibie[t][0]++;
			if((student[s].grade[t]>=80)&&(student[s].grade[t]<=89))
				leibie[t][1]++;
			if((student[s].grade[t]>=70)&&(student[s].grade[t]<=79))
				leibie[t][2]++;
			if((student[s].grade[t]>=60)&&(student[s].grade[t]<=69))
				leibie[t][3]++;
			if((student[s].grade[t]>=0)&&(student[s].grade[t]<=59))
				leibie[t][4]++;
		}
		for(i=0;i<5;i++)
			baifenbi[t][i]=leibie[t][i]/n;
	}
	for(t=0;t<j;t++)
	{
		for(s=0;s<5;s++)
		{
			fprintf(fp,"%3f",leibie[t][s]);
			fprintf(fp,"%3f",baifenbi[t][s]);
		}
		fprintf(fp,"\n");
	}
	fclose(fp);
	printf("�ɹ������ļ���\n");
}



















void input(struct person *h,int n,int j)//��ѧ����Ϣ���浽�ļ�
{
	char name3[30];
	FILE *fp;
	printf("�������ļ�������β��Ϊ.txt��\n");
	scanf("%s",name3);
	if((fp=fopen(name3,"w"))==NULL)
		printf("can not open the file!\n");
	struct person *p;
	int u,i;
	int t,s;
	p=h;
	for(i=0;i<n;i++)
	{
		student[i].num=p->num;
		strcpy(student[i].name,p->name);
		for(u=0;u<j;u++)
			student[i].grade[u]=p->grade[u];
		p=p->next;
	}
	for(t=0;t<n;t++)
	{
		fprintf(fp,"%3d%s",student[t].num,student[t].name);
		for(s=0;s<j;s++)
			fprintf(fp,"%5f",student[t].grade[s]);
	}
	fclose(fp);
	printf("�ɹ������ļ���\n");
}










int menu()//���˵�
{
	int p;
	printf("\n");
	printf("\n");
	printf("�밴�����б�ѡ���ܣ����빦��ǰ����ź�س����ɣ�\n");
	printf("0.exit\n");
	printf("1.Read from a file\n");
	printf("2.Calculate total and average score of every course\n");
	printf("3.Calculate total and average score of every student\n");
	printf("4.Sort in descending order by to tal score of every student\n");
	printf("5.Sort in ascending order by total score of every stuednet\n");
	printf("6.Sort in ascending order by number\n");
	printf("7.Sort in dictionary order by name\n");
	printf("8.Search by number\n");
	printf("9.Search by name\n");
	printf("10.Statistic analysis for every course\n");
	printf("11.List record\n");
	printf("12.Write to a file\n");
	printf("\n");
	printf("\n");
	scanf("%d",&p);
	return p;
}









struct person * wenjianduru1(int n,int j)//���ļ��ж���ѧ��������Ϣ
{
	struct person *h,*p,*q;

		int a,b;
		int c=0;
		FILE *f1;
		printf("������Ҫ������ļ�������β��Ϊ.txt��\n");
		scanf("%s", filename);
		if (((f1 = fopen(filename, "r")) == NULL))
			printf("�������");
			fscanf(f1,"%3d",h->num);
			fscanf(f1,"%s",h->name);
			for(b=0;b<j;b++)
				fscanf(f1,"%3f",h->grade[b]);
			c++;
			q=h;
			p=q->next;
	    while(feof(f1))
		{
			fscanf(f1,"%3d",p->num);
			fscanf(f1,"%s",p->name);
			for(b=0;b<j;b++)
				fscanf(f1,"%3f",p->grade[b]);
			c++;
			p=p->next;
			q->next=p;
			q=p;
		}
	    fclose(f1);
		return h;
		printf("�ɹ�����ѧ����Ϊ��%d\n",c);
}














int main()
{
	PlaySound("123.wav", NULL, SND_FILENAME | SND_ASYNC);
	struct person *h;
	int n,j;//nΪ������jΪ��Ŀ��
	int p;
	int y;
	printf("\n");
	printf("\n");
	printf("��ӭ����ѧ���ɼ���Ϣ����ϵͳ��\n");
	printf("\n");
	printf("\n");
	printf("��������Ҫ¼���ѧ������(ѧ����������30��\n");
	scanf("%d",&n);
	printf("������ÿ��ѧ���Ŀ��Կ�Ŀ������Ŀ��������6��\n");
	scanf("%d",&j);
	h=creat(n,j);//��������
	y=jiancha(h,n,j);//���ѧ���Ƿ��ظ�
	while(y==0)
	{
		h=creat(n,j);
		y=jiancha(h,n,j);
	}
	p=menu();
	while(p!=0)
	{
	switch(p)
	{
	case 1: {wenjianduru1(n,j);p=menu();break;}
	case 2: {kechengtongji(h,n,j);p=menu();break;}
	case 3: {gerentongji(h,n,j);p=menu();break;}
	case 4: {sortdown(h,n,j);p=menu();break;}
	case 5: {sortup(h,n,j);p=menu();break;}
	case 6: {numsort(h,n,j);p=menu();break;}
	case 7: {namesort(h,n,j);p=menu();break;}
	case 8: {numsearch(h,n,j);p=menu();break;}
	case 9: {namesearch(h,n,j);p=menu();break;}
	case 10: {percent(h,n,j);p=menu();break;}
	case 11: {print(h,n,j);p=menu();break;}
	case 12: {input(h,n,j);p=menu();break;}
	}
	}
	return 0;
}

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









struct person *creat(struct person *h,int n,int j)//从文件读入信息，创建链表
{
	struct person *h;//定义头结点
	h=wenjianduru1();
	struct person *p,*q;
	int m,i,k;//定义循环变量
	FILE *fp;
	printf("请输入要将信息保存到的文件名（结尾需为.txt）\n");
	scanf("%s",filename1);
	if((fp=fopen(filename1,"w"))==NULL)
		printf("can not open the file!\n");
	h=q=(struct person *)malloc(sizeof(struct person));
	printf("请输入第1个人的信息:学号 姓名（姓名只支持英文输入） ");
	for(k=1;k<=j;k++)
        printf("第%d科成绩 ",k);
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
		printf("请输入第%d个人的信息:学号 姓名 ",i);
		for(k=1;k<=j;k++)
            printf("第%d科成绩 ",k);
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
				printf("学号输入重复,请重新输入\n");
				return 0;
			}
		}
	}
	return 1;
}


























void kechengtongji(struct person *h,int n,int j)//输出每科平均成绩和总成绩
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
		printf("第%d科的总成绩为%f\n",p+1,sum);
		printf("第%d科的平均成绩为%f\n",p+1,pingjun);
		sum=0;
		o=h;
	}
}

















void gerentongji(struct person *h,int n,int j)//输出个人各科成绩和总成绩
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
		printf("第%d个人的总成绩为%f\n",q,sum);
		printf("第%d个人的平均成绩为%f\n",q,pingjun);
		q++;
		sum=0;
		o=o->next;
	}
}














void sortdown(struct person *h,int n,int j)//从高到低输出学生总分
{
	struct person *p,*o;
	int u,i,v,d;
	int t,s;
	float sum=0,pingjun;
	float temp;//交换中间变量
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
	printf("分数从高到低学生排名为：\n");
	for(v=0;v<n;v++)
    {
        printf("%d %s %d %f ",v+1,student[v].name,student[v].num,student[v].zong);
        for(i=0;i<j;i++)
            printf("%f ",student[v].grade[i]);
        printf("\n");
        student[v].ranking=v+1;
    }
}














void sortup(struct person *h,int n,int j)//从低到高输出学生总分
{
	struct person *p,*o;
	int u,i,v;
	int t,s,d;
	float sum=0,pingjun;
	float temp;//交换中间变量
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
	printf("分数从低到高学生排名为：\n");
	for(v=0;v<n;v++)
    {
        printf("%d %s %d %f ",n-v,student[v].name,student[v].num,student[v].zong);
        for(i=0;i<j;i++)
            printf("%f ",student[v].grade[i]);
        printf("\n");
		student[v].ranking=n-v;
    }
}












void numsort(struct person *h,int n,int j)//按学号由小到大排序
{
    struct person *p,*o;
	int u,i,v;
	int t,s,d;
	float sum=0,pingjun;
	float temp;//交换中间变量
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
	printf("按学号从小到大排序学生信息为：\n");
	for(v=0;v<n;v++)
    {
        printf("%s %d %f ",student[v].name,student[v].num,student[v].zong);
        for(i=0;i<j;i++)
            printf("%f ",student[v].grade[i]);
        printf("\n");
    }
}





















void namesort(struct person *h,int n,int j)//按姓名字典顺序排序
{
    struct person *p,*o;
	int u,i,v;
	int t,s,d;
	float pingjun,sum=0;
	float temp;//交换中间变量
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
	printf("按姓名字典顺序排序学生信息为：\n");
	for(v=0;v<n;v++)
    {
        printf("%s %d %f ",student[v].name,student[v].num,student[v].zong);
        for(i=0;i<j;i++)
            printf("%f ",student[v].grade[i]);
        printf("\n");
    }
}


















void namesearch(struct person *h,int n,int j)//按姓名查找
{
	struct person *p;
	int u,i,v;
	int t,s,k=0;
	char c;
	float temp;//交换中间变量
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
	printf("请输入你要查询的学生姓名：\n");
	scanf("%s",name1);
	c=getchar();
	for(i=0;i<n;i++)
	{
		if((strcmp(name1,student[i].name))==0)
			k++;
	}
	while(k==0)
	{
		printf("未找到该学生信息,请重新输入\n");
		printf("请输入你要查询的学生姓名：\n");
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















void numsearch(struct person *h,int n,int j)//按学号查找
{
	struct person *p;
	int u,i,v;
	int t,s,d,k=0;
	float temp;//交换中间变量
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
	printf("请输入你要查询的学生学号：\n");
	scanf("%d",&d);
	for(i=0;i<n;i++)
	{
		if(d==student[i].num)
			k++;
	}
	while(k==0)
	{
		printf("未找到该学生信息,请重新输入\n");
		printf("请输入你要查询的学生学号：\n");
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














void print(struct person *h,int n,int j)//将学生信息输出到显示器
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

















void percent(struct person *h,int n,int j)//统计每个类别的人数及百分比
{
	struct person *p;
	int u,i;
	int t,s;
	float leibie[6][5];
	float baifenbi[6][5];
	char name4[30];
	FILE *fp;
	printf("请输入文件名（结尾需为.txt）\n");
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
	printf("成功存入文件！\n");
}



















void input(struct person *h,int n,int j)//将学生信息保存到文件
{
	char name3[30];
	FILE *fp;
	printf("请输入文件名（结尾需为.txt）\n");
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
	printf("成功存入文件！\n");
}










int menu()//主菜单
{
	int p;
	printf("\n");
	printf("\n");
	printf("请按如下列表选择功能（输入功能前的序号后回车即可）\n");
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









struct person * wenjianduru1(int n,int j)//从文件中读出学生个人信息
{
	struct person *h,*p,*q;

		int a,b;
		int c=0;
		FILE *f1;
		printf("请输入要读入的文件名（结尾需为.txt）\n");
		scanf("%s", filename);
		if (((f1 = fopen(filename, "r")) == NULL))
			printf("读入出错！");
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
		printf("成功读入学生数为：%d\n",c);
}














int main()
{
	PlaySound("123.wav", NULL, SND_FILENAME | SND_ASYNC);
	struct person *h;
	int n,j;//n为人数，j为科目数
	int p;
	int y;
	printf("\n");
	printf("\n");
	printf("欢迎进入学生成绩信息管理系统！\n");
	printf("\n");
	printf("\n");
	printf("请输入需要录入的学生人数(学生数不超过30）\n");
	scanf("%d",&n);
	printf("请输入每名学生的考试科目数（科目数不超过6）\n");
	scanf("%d",&j);
	h=creat(n,j);//创建链表
	y=jiancha(h,n,j);//检查学号是否重复
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

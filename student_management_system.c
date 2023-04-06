#include <stdio.h>
#include <string.h>
#include <stdlib.h>   //提供 exit() 函数支持  
#define SIZE 100000
//#include"conio.h"

//声明函数原型
void finput();    //存入数据
void flist();     //输出数据
void fsearch();   //查找数据
void fadden();    //增加数据
void fchange();   //修改数据
void ftaxis();    //数据排序
void stat();      //统计数据

//定义结构体 
struct student 
{
	int num;        //存放
	char name[10];  //定义名字数组变量
	int C;          //C 语言成绩
	int Maths;      //数学课成绩
	int En;         //英语课成绩
	float ave;      //三门课平均成绩
} stu[SIZE];        //在定义结构体时同时声明结构体变量

int main() 
{
	int n;
	for(;;)          //使程序能够循环，在循环内部判断何时结束 
	{
		printf("\n\n");        //与上次的输出结果保持间隔，便于美观 
		printf("	_________________________________\n");//菜单输出 
		printf("	|           MENU                |\n");
		printf("	|       1.Input data            |\n");               
		printf("	|       2.Output data           |\n");
		printf("	|       3.Search data           |\n");
		printf("	|       4.Add data              |\n");
		printf("	|       5.Revise data           |\n");
		printf("	|       6.Sort data             |\n");
		printf("	|       7.Statistics            |\n");
		printf("	|       8.  quit                |\n");
		printf("	|_______________________________|\n");
		printf("  Please choose your function:(1-8):");          //功能选择 
		scanf("%d",&n);
		printf("\n");
		if(n>0&&n<=8) {
			switch(n) {
				case 1:
					finput();
					break;
				case 2:
					flist();
					break;
				case 3:
					fsearch();
					break;
				case 4:
					fadden();
					break;
				case 5:
					fchange();
					break;
				case 6:
					ftaxis();
					break;
				case 7:
					stat();
				case 8:		 
		printf("\n    ~~~~~~~~~~~~~~~~~~~~~~~~~~\n");     //退出提示
		printf("             Goodbye!         \n");
		printf("    ~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
					exit(0);//将程序退出 
			}
		} else //没有按规范选择功能，要进行错误提示     //错误提示
		{
		printf("\n    ~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("           error input!       \n");
		printf("    ~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
//			break; //应该将这一句话去掉才能使在输错的情况下也进行菜单循环 
		}
	}
	return 0;
}
/*
主函数部分结束 
*/ 


/*
下面是模块化设计
每个功能对应一个函数 
*/ 

//part 1 : 进行信息录入 
void finput() 
{
	FILE *fp;            //声明指针变量 
	int i,p;
	fp=fopen("grades","wb");          //首次打开文件， 若没有文件将会自动创建新文件 
	for(i=0; i<SIZE; i+1) 
	{
		printf("1 to continue and 0 to end input: ");        //询问是否继续输入 
		scanf("%d",&i);
		if(i==0) 
		{
			fclose(fp);
			return;
		} 
		else {
			printf("Please inut your school number, C grade, Math grade, English grade:\n");
			scanf("%d%s%d%d%d",&stu[i].num,stu[i].name,&stu[i].C,&stu[i].Maths,&stu[i].En);
			stu[i].ave=(stu[i].C+stu[i].Maths+stu[i].En)/3.0;
			fwrite(&stu[i],sizeof(struct student),1,fp);
		}
	}
	fclose(fp);         //记得关闭文件，这是一个好习惯！ 
}


//part 2: 将结果输出 
void flist() 
{
	FILE *fp;
	int i;
	fp=fopen("grades","rb");
	printf("____________________________________________________________________________________________________\n"); 
	printf("|                                                  Report                                           |\n");
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	printf("|        ID      |    name   |    C grade    |    Math grade   |   English grade   |    Average     |\n");
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	for(i=0; fread(&stu[i],sizeof(struct student),1,fp)==1; i++) 
		printf("|%11d%15s%13d%17d%18d%19.2f\n",stu[i].num,stu[i].name,stu[i].C,stu[i].Maths,stu[i].En,stu[i].ave);
		/*
		此处采用字宽输入比加空格更好， 因为若是使用空格输入，当学号或者名字前后输入的长度不一致时，格式会乱掉，导致无法对其格式 
		*/ 
	printf("|___________________________________________________________________________________________________|\n\n");
	fclose(fp);
}

//part 3：查找数据 
void fsearch() 
{
	FILE *fp;
	int i,num,flag=0;//flag 用来判断是否需要进行错误提示 
	fp=fopen("grades","rb");
	rewind(fp);
	printf("Which one are you searching? Input the School number: ");
	scanf("%d",&num);
	
	for(i=0; i<=SIZE; i++)
	{
		if(stu[i].num==num) 
		{
			printf("____________________________________________________________________________________________________\n");//与上文采用相同的输出格式，会显得统一整洁 
			printf(" Here are the rusults                                                                               \n");
			printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
			printf("|        ID      |    name   |    C grade    |    Math grade   |   English grade   |    Average     \n");
			printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
			printf("|%11d%15s%13d%17d%18d%19.2f\n",stu[i].num,stu[i].name,stu[i].C,stu[i].Maths,stu[i].En,stu[i].ave);
			printf("|__________________________________________________________________________________________________|\n\n");
			flag+=1;
		}
	}
	if(flag==0)
	{
		printf("\n    ~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("           error input!       \n");
		printf("    ~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	}
//	printf("___________________________________________________________________________________________________________\n\n");
	fclose(fp);
}

//part 4：增加数据 
void fadden() 
{
	int i,s;
	FILE *fp;
	fp=fopen("grades","ab+");
	rewind(fp);
	printf("___________________________________________________________________________ ________________________\n");
	printf("|                                                  Report                                          |\n");
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	printf("|        ID      |    name   |    C grade    |    Math grade   |   English grade   |    Average     \n");
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	for(i=0; fread(&stu[i],sizeof(struct student),1,fp)==1; i++) 
		printf("|%11d%15s%13d%17d%18d%19.2f\n",stu[i].num,stu[i].name,stu[i].C,stu[i].Maths,stu[i].En,stu[i].ave);
	printf("____________________________________________________________________________________________________\n");
	s=i;	         //记录学号位置，从此处开始增加新的数据 
	for(i=s; i<SIZE; i++) {
		printf("1 to continue and 0 to end input: ");
		scanf("%d",&i);
		if(i==0) 
		{
			fclose(fp);
			return;
		} else 
		{
			printf("Please inut your school number, C grade, Math grade, English grade:\n");
			scanf("%d%s%d%d%d",&stu[i].num,stu[i].name,&stu[i].C,&stu[i].Maths,&stu[i].En);
			stu[i].ave=(stu[i].C+stu[i].Maths+stu[i].En)/3.0;
			fwrite(&stu[i],sizeof(struct student),1,fp);
		}
	}
	fclose(fp);
}

//part 5：修改数据 
void fchange() 
{
	FILE *fp;
	int i,num,n;
	int flag=0;
	printf("Which one are you searching? Input the School number: ");
	scanf("%d",&num);
	printf("\n");
	for(i=0; i<=SIZE; i++)
		if(stu[i].num==num) 
		{
			printf("____________________________________________________________________________________________________\n");
			printf("|                                                  Report                                           |\n");
			printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
			printf("|        ID      |    name   |    C grade    |    Math grade   |   English grade   |    Average     |\n");
			printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
			printf("|%11d%15s%13d%17d%18d%19.2f\n",stu[i].num,stu[i].name,stu[i].C,stu[i].Maths,stu[i].En,stu[i].ave);
			printf("|___________________________________________________________________________________________________|\n\n");
			n=i;
			flag=1;
			break;
		}
	if(flag==0) {
		printf("\n    ~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("           error input!       \n");
		printf("    ~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		return;
	}
	printf("\n\n");
	fp=fopen("grades","rb+");
	fseek(fp,n*sizeof(struct student),0);
	printf("Please inut your school number, C grade, Math grade, English grade:\n");
	scanf("%d%s%d%d%d",&stu[i].num,stu[i].name,&stu[i].C,&stu[i].Maths,&stu[i].En);
	stu[i].ave=(stu[i].C+stu[i].Maths+stu[i].En)/3.0;
	fwrite(&stu[i],sizeof(struct student),1,fp);
	fclose(fp);
	fp=fopen("grades","rb");
	printf("_______________________________________________________________________________ _____________________\n");
	printf("|                                                  Report                                           |\n");
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	printf("|        ID      |    name   |    C grade    |    Math grade   |   English grade   |    Average     |\n");
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	for(i=0; fread(&stu[i],sizeof(struct student),1,fp)==1; i++) 
	{
		printf("|%11d%15s%13d%17d%18d%19.2f\n",stu[i].num,stu[i].name,stu[i].C,stu[i].Maths,stu[i].En,stu[i].ave);
	}
	printf("|___________________________________________________________________________________________________|\n");
	fclose(fp);
}

//part 6：按平均成绩进行排序 
void ftaxis() 
{
	int i,j,n;
	FILE *fp;
	struct student t;
	fp=fopen("grades","rb");
	printf("____________________________________________________________________________________________________ \n");
	printf("|                                                  Report                                           |\n");
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	printf("|        ID      |    name   |    C grade    |    Math grade   |   English grade   |    Average     |\n");
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	for(i=0; fread(&stu[i],sizeof(struct student),1,fp)==1; i++)
		printf("|%11d%15s%13d%17d%18d%19.2f\n",stu[i].num,stu[i].name,stu[i].C,stu[i].Maths,stu[i].En,stu[i].ave);
	printf("|___________________________________________________________________________________________________|\n\n");
	fclose(fp);
	n=i;
	for(i=0; i<n; i++)
		for(j=i+1; j<n; j++)
			if(stu[i].ave<stu[j].ave) {
				t=stu[i];
				stu[i]=stu[j];
				stu[j]=t;
			}
	fp=fopen("grades","wb");
	printf("\n\n\n");
	printf("_____________________________________________________________________________________________________\n");
	printf("|                                                  Report                                           |\n");
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	printf("|        ID      |    name   |    C grade    |    Math grade   |   English grade   |    Average     |\n");
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	for(i=0; i<n; i++) {
		fwrite(&stu[i],sizeof(struct student),1,fp);
		printf("|%11d%15s%13d%17d%18d%19.2f\n",stu[i].num,stu[i].name,stu[i].C,stu[i].Maths,stu[i].En,stu[i].ave);
	}
	printf("|___________________________________________________________________________________________________|\n");
	fclose(fp);
}

//part 6: 统计指定分数之上的人数
void stat()
{
	FILE *fp;
	int i,num,flag=0,count=0;//flag 用来判断是否需要进行错误提示, count用来统计个数
	float score_; 
	fp=fopen("grades","rb");
	rewind(fp);
	printf("Do you want to know the percentage of the total score?\nEnter your number: ");
	scanf("%f",&score_);
	
	for(i=0; i<=SIZE; i++)
	{
		if(score_ < stu[i].ave ) 
		{
			count++;
			flag=1;
		}
	}
	if(flag == 1)
		printf("%d in total above your number\n",count);
	if(flag==0)
	{
		printf("\n    ~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("           error input!       \n");
		printf("    ~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	}
//	printf("___________________________________________________________________________________________________________\n\n");
	fclose(fp);
}

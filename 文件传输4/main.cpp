//
//  main.cpp
//  文件传输4
//
//  Created by s20181106119 on 2019/6/27.
//  Copyright © 2019 s20181106119. All rights reserved.
//
//
#include<iostream>
#include<fstream>
using namespace std;
struct student{
    char name1[5];       //学生姓名
    char number[5];      //学号
    char  colleage[10];   //学院
    double ave;
};
struct referee{
    char name2[7];    //裁判姓名
    int score[5];    //分数
};

int main()
{
    
    ifstream in("/Users/s20181106119/Desktop/学生信息.txt");
   
   
    struct student student[5];
    struct  referee referee[7];
        int i;
        cout<<"1"<<endl;;
        for(i=0;i<5;i++)
        {
            in>>student[i].name1>>student[i].number>>student[i].colleage;
        }
    
    
     ifstream inf ("/Users/s20181106119/Desktop/裁判信息及分数.txt");
        cout<<"2"<<endl;
        int l,k,j,t=0,sum=0;
        for(l=0;l<7;l++)
        {
            inf>>referee[l].name2;
      
            for(j=0;j<7;j++)
            {
                inf>>referee[l].score[j];
            }
        }
    
        for(l=0;l<5;l++)
        {
            for(j=0;j<7;j++)
            {
                if(t<referee[l].score[j])
                {
                    t=referee[l].score[j];
                    referee[l].score[j]=referee[l].score[j+1];
                    referee[l].score[j+1]=t;
                }
            }

           
        }
   
        for(l=0;l<5;l++)
        {
            for(j=1;j<6;j++)
            {
                sum=sum+referee[l].score[j];
            }
            student[l].ave=sum/5;
            sum=0;
        }
    for(k=0;k<5;k++)
    {
        int max=0;
        if(student[k].ave>max)
        {
            max=student[k].ave;
            student[k].ave=student[k+1].ave;
            student[k+1].ave=max;
        }
    }
    
     
    ofstream output("/Users/s20181106119/Desktop/最终排名.txt");
    if(output.is_open())
    {
        int k;
        for(k=0;k<5;k++)
        {
            output<<student[k].name1<<" "<<student[k].colleage<<" "<<student[k].number<<" "<<student[k].ave<<endl;
        
        }
        
        output.close();
   
    }
}


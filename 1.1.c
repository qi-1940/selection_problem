/*
编写一个程序解决选择问题。令k=N/2。画出表格显示你的程序对于N为不同值的运行时间。
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int * a,int * b){
    int t=*b;
    *b=*a;
    *a=t;
}

void sort(int * temp,int k){//从大到小排序
    for(int i=0;i<k;i++){
        for(int j=0;j<k-i;j++){
            if(temp[j]<=temp[j+1]&&j+1<k){
                swap(&temp[j],&temp[j+1]);
            }
        }
    }
    
    return;
}

int main(){

    FILE * fp;
    fp=fopen("1.1.csv","w");


    printf("Time\t\tN\t\tOutput\n");
    fprintf(fp,"Time,N,Output\n");

    int i=1;
    int N,k;
    for(;i<=40;i++){//i代表多少组测试数据
        clock_t start_time = clock();
        N=2000*i;
        k=N/2;
        int temp[k],j=0;//j代表这是输入的第几个元素，从0开始取值，到N-1
        for(int input=1;input<=N;input++){//input代表每组的输入值
            if(j<k){//如果数组没满
                temp[j++]=input;
            }
            
            if(j==k){//如果数组刚满
                sort(temp,k);
                j++;
            }
            else if(j>k&&input>*(temp+k-1)){//如果数组满了而且新输入的数大于数组里最小的数
                int y=1;
                while(k-y>=1&&input>*(temp+k-1-y)){
                    *(temp+k-y)=*(temp+k-1-y);
                    y++;
                }
                *(temp+k-y)=input;
                j++;
            }
        }
        double time1 = 1000*(clock()-start_time)/CLOCKS_PER_SEC;
        printf("%.6g\t\t%d\t\t%d\n",time1,N,*(temp+k-1));
        fprintf(fp,"%.6g,%d,%d\n",time1,N,*(temp+k-1));
    }
    printf("Over!\n");
    fclose(fp);
    return 0;
}
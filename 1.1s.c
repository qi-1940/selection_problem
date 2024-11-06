/*
编写一个程序解决选择问题。令k=N/2。画出表格显示你的程序对于N为不同值的运行时间。
*/

#include<stdio.h>
#include<time.h>
#include"priority_queue.h"

int main (){

    FILE * fp;
    fp=fopen("1.1s.csv","w");


    printf("Time\t\tN\t\tOutput\n");
    fprintf(fp,"Time,N,Output\n");

    int i=1;
    int N,k,output;
    for(;i<=40;i++){//i代表多少组测试数据
        clock_t start_time = clock();
        N=2000*i;//2000代表相邻的两组数据中N的差值
        k=N/2;
        //k=N-k+1;//因为堆获得的是第多少个最小的元素，这样程序就能获得第k个最大的元素
    
        int input[N+1];//用于输入数据的数组
        input[0]=-1;
        for(int i=1;i<=N;i++){
            input[i]=N-i+1;
        }

        //用数组构建堆
        PriorityQueue h=BuildHeap(input,N+1);
        
        //删除k个结点
        for(int i=0;i<(N-k);i++){
            DeleteMin(h);
        }

        //获取答案
        output=DeleteMin(h);
    
        double time1 = 1000*(clock()-start_time)/CLOCKS_PER_SEC;
        
        printf("%.6g\t\t%d\t\t%d\n",time1,N,output);
        fprintf(fp,"%.6g,%d,%d\n",time1,N,output);
    }


    printf("Over!\n");
    fclose(fp);
    return 0;
}
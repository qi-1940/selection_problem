#include<stdio.h>
#include<stdlib.h>
#include"priority_queue.h"

struct Heap{
    int capacity;
    int size;
    int * heap_int;
};

//
PriorityQueue Initialize(int max_elements){
    PriorityQueue H;
    H=malloc(sizeof(struct Heap));
    H->heap_int=malloc((max_elements+1)*sizeof(int));
    H->capacity=max_elements;
    H->size=0;
    H->heap_int[0]=-1;

    return H;
}

//
void Insert(PriorityQueue H,int input){
    int i;
    for(i=++H->size;H->heap_int[i/2]>input;i/=2){//初始创建空穴，如果输入比空穴的父节点小，则进行循环
        H->heap_int[i]=H->heap_int[i/2];//空穴移到其父节点的位置
    }
    H->heap_int[i]=input;
}

//返回最小元素的值
int DeleteMin(PriorityQueue H){


    int output;
    if(H->size>0){
        output=H->heap_int[1];
    }
    else{
        printf("error!\n");
        return -1;
    }
    int Child;
    //获取最后一个元素，要把它放入堆中
    int LastElement = H->heap_int[H->size--];
    int i;
    for(i=1;i*2<=H->size;i=Child){//i是空穴的下标
        Child=i*2;
        if(Child!=H->size&&H->heap_int[Child]>H->heap_int[Child+1])
            Child++;
        if(LastElement>H->heap_int[Child])//如果子节点比最后结点小，子节点上
            H->heap_int[i]=H->heap_int[Child];
        else//最后一个结点比空穴的子结点小，进入空穴，循环退出
            break;
    }
    H->heap_int[ i ] = LastElement;
    return output;
}

PriorityQueue BuildHeap(int * input,int size){
    PriorityQueue output = Initialize(size);
    for(int i=1;i<size;i++){
        output->heap_int[i]=input[i];//构建无序堆
    }
    output->size=size-1;

    //使堆有序
    int i,Child,temp,value_i;
    for(i=(size-1)/2;i>0;i--){//遍历所有有子结点的节点
        value_i=output->heap_int[i];
        Child=i*2;
        //找出较小子结点,或者只有一个子结点的话则Child不变
        if(Child!=output->size&&output->heap_int[Child+1]<output->heap_int[Child]){
            Child++;
        }
        for(temp=i;value_i>output->heap_int[Child];){
            output->heap_int[temp]=output->heap_int[Child];
            temp=Child;
            if(temp*2>output->size)break;
            Child=temp*2;
            //找出较小子结点,或者只有一个子结点的话则Child不变
            if(Child<output->size&&output->heap_int[Child+1]<output->heap_int[Child]){
                Child++;
            }
        }
        output->heap_int[temp]=value_i;
    }
    /*
    for(int i=1;i<=output->size;i++){
        printf("%d ",output->heap_int[i]);
    }
    printf("\n");
    */
    return output;
}




#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

struct Heap;
typedef  struct Heap * PriorityQueue;

PriorityQueue Initialize(int max_elements);

void Insert(PriorityQueue H,int input);

int DeleteMin(PriorityQueue H);

PriorityQueue BuildHeap(int * input,int size);

#endif
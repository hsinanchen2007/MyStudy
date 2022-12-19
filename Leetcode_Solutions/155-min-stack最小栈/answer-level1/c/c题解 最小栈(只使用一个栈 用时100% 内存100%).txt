下面是我有一次的运行结果
```
执行用时 :28 ms, 在所有 C 提交中击败了100.00%的用户
内存消耗 :13.8 MB, 在所有 C 提交中击败了100.00%的用户
```
![test.jpg](https://pic.leetcode-cn.com/12cd37850797f4c368af93c35453b71fc1242e5f7ebf669b82269fee4aab6c85-test.jpg)
### 思路：每一次执行push操作时，进行两次入栈，第一次入栈此元素，第二次入栈此时栈中最小的元素；执行pop操作与之相对
```c
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1600

typedef struct {
    int *data;
    int top;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack *obj=(MinStack *)malloc(sizeof(MinStack));
    obj->data=(int *)malloc(MAXSIZE*sizeof(int));
    obj->top=-1;
    return obj;
}

void minStackPush(MinStack* obj, int x) {
  if(obj->top==MAXSIZE-1){
      
  }else if(obj->top==-1){
      obj->top++;
      obj->data[obj->top]=x;
      obj->top++;
      obj->data[obj->top]=x;
  }else{
      int tmp=obj->data[obj->top];
      obj->top++;
      obj->data[obj->top]=x;
      if(tmp<x){
        obj->top++;
        obj->data[obj->top]=tmp;
      }else{
        obj->top++;
        obj->data[obj->top]=x;
      }
  }
}

void minStackPop(MinStack* obj) {
  if(obj->top==-1){
      
  }else{
      obj->top--;
      obj->top--;
  }
}

int minStackTop(MinStack* obj) {
  if(obj->top==-1){
      return;
  }
  return obj->data[obj->top-1];
  
}

int minStackGetMin(MinStack* obj) {
  return obj->data[obj->top];
}

void minStackFree(MinStack* obj) {
    free(obj->data);
    obj->data=NULL;
    free(obj);
    obj=NULL;
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
```
### 一般方法：找最小值时遍历一遍，时间复杂度O[n]
```c
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 800

typedef struct {
    int *data;
    int top;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack *obj=(MinStack *)malloc(sizeof(MinStack));
    obj->data=(int *)malloc(MAXSIZE*sizeof(int));
    obj->top=-1;
    return obj;
}

void minStackPush(MinStack* obj, int x) {
  if(obj->top==MAXSIZE-1){
      
  }else{
      obj->top++;
      obj->data[obj->top]=x;
  }
}

void minStackPop(MinStack* obj) {
  if(obj->top==-1){
      
  }else{
      obj->top--;
  }
}

int minStackTop(MinStack* obj) {
  if(obj->top==-1){
      return;
  }
  return obj->data[obj->top];
  
}

int minStackGetMin(MinStack* obj) {
  if(obj->top==-1) return;
  if(obj->top==0){
      return obj->data[obj->top];
  }
  int min=obj->data[0];
  for(int i=0;i<=obj->top;i++){
      if(obj->data[i]<min){
          min=obj->data[i];
      }
  }
  return min;
}

void minStackFree(MinStack* obj) {
    free(obj->data);
    obj->data=NULL;
    free(obj);
    obj=NULL;
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
```


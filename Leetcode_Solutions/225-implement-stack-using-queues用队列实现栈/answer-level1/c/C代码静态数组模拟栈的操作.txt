### 解题思路
使用一个静态数组stack来作为栈的容器，MyStack结构体中top和bottom成员分别表示栈顶和栈底的位置

### 代码

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 512

typedef struct {
	int top;
	int bottom;
	int stack[MAXSIZE];
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
	MyStack *s = (MyStack *)malloc(sizeof(MyStack));
	memset(s, 0, sizeof(MyStack));
	return s;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
	obj->stack[obj->top] = x;
	obj->top++;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
	obj->top--;
	return (obj->stack[obj->top]);
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
	return (obj->stack[obj->top - 1]);
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
	return (obj->top == obj->bottom);
}

void myStackFree(MyStack* obj) {
	free(obj);
}

![无标题.png](https://pic.leetcode-cn.com/a11a32e12c4336daff43f850a09cdb8209de616c2652c36bd34d0387eda99b51-%E6%97%A0%E6%A0%87%E9%A2%98.png)


```
typedef struct {
    int data[10000];
    int head;
    int tail;
} queue;

void queueIN(queue * q, int number)
{
    q->data[q->head] = number;
    q->head += 1;
}

int queueOUT(queue * q)
{
    q->tail += 1;
    int out = q->data[q->tail];
    return out;
}

typedef struct {
    queue q1;
    queue q2;
} MyStack;


/** Initialize your data structure here. */

MyStack* myStackCreate() {
MyStack * st = (MyStack *)malloc(sizeof(MyStack));
st->q1.head = 0;
st->q1.tail = 0;
st->q2.head = 0;
st->q2.tail = 0;
return st;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    int tmp; 
for(;obj->q1.head > obj->q1.tail;)
{
    tmp = queueOUT(&obj->q1);
    queueIN(&obj->q2, tmp);
}
queueIN(&obj->q1, x);
for(;obj->q2.head > obj->q2.tail;)
{
    tmp = queueOUT(&obj->q2);
    queueIN(&obj->q1, tmp);
}
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
int out = queueOUT(&obj->q1);
return out;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
int tmp;
int top = queueOUT(&obj->q1);
queueIN(&obj->q2, top);
for(;obj->q1.head > obj->q1.tail;)
{
    tmp = queueOUT(&obj->q1);
    queueIN(&obj->q2, tmp);
}
for(;obj->q2.head > obj->q2.tail;)
{
    tmp = queueOUT(&obj->q2);
    queueIN(&obj->q1, tmp);
}
return top;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
return (obj->q1.head == obj->q1.tail);
}

void myStackFree(MyStack* obj) {

}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/
```
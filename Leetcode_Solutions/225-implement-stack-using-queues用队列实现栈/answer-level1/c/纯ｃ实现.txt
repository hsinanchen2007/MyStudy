### 解题思路：
**主操作**
使用的是两个循环队列，始终保持一个队列为空, 然后两个队列来回倒腾，最后一个元素就是所要的栈顶元素：<br>
(1)`myStackPush(MyStack* obj, int x)`操作：
就是将元素压到不为空的一个队列里
(2)`myStackPop(MyStack* obj) `操作：
就是将一个不为空的全部压到另一个为空的队列里，然后记录了最后一个，最后一个元素并没有被放到另一个队列里（当你拿出来时就判断是否为空，并没有进入第二个队列）
(3)`myStackTop(MyStack* obj)`操作：
同删除操作，只是记录了最后一个移动的元素值


```cpp
typedef struct MyQueue{
    int *data;
    int head, tail;
    int size, cnt;
}MyQueue;

MyQueue *MyQueueCreate(int size) {
    MyQueue *q = (MyQueue *)malloc(sizeof(MyQueue));
    q->data = (int *)malloc(sizeof(int) * size);
    q->head = q->tail = 0;
    q->cnt = 0;
    q->size = size;
    return q;
}

void MyQueuePush(MyQueue *obj, int x) {
    if(obj == NULL) return ;
    if(obj->cnt == obj->size)return;
    obj->data[obj->tail++] = x;
    if(obj->tail == obj->size) obj->tail -= obj->size;//当值满的时候需，此时假溢出，应该放在开头
    obj->cnt ++;
    return;
}

int MyQueuePop(MyQueue *obj) {
    if(obj == NULL) return 0;
    if(obj->cnt == 0)return 0;
    obj->head++;
    if(obj->head==obj->size) obj->head -= obj->size;
    obj->cnt -= 1;
    return 1;
}

int MyQueueFront(MyQueue *obj) {
    return obj->data[obj->head];
}

int MyQueueEmpty(MyQueue *obj) {
    return obj->cnt == 0;
}
void MyQueueFree(MyQueue *obj) {
    if(obj == NULL) return;
    free(obj->data);
    free(obj);
    return;
}

typedef struct {
    MyQueue *q1, *q2;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {　//初始化栈
    int size = 1024;
    MyStack *s = (MyStack *)malloc(sizeof(MyStack));
    s->q1 = MyQueueCreate(size);//初始化两个队列q1和q2;
    s->q2 = MyQueueCreate(size);
    return s;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {//压栈操作：
    if(!MyQueueEmpty(obj->q1)) {//如果q1不为空时将值压入q1中
        MyQueuePush(obj->q1, x);
    } else {//如果q1为空时将值压入p2;
        MyQueuePush(obj->q2, x);
    }
    return;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {//删除栈顶操作
    MyQueue *p = MyQueueEmpty(obj->q1) ? obj->q2 : obj->q1;//如果q1为空ｐ为q2，那么ｑ就为ｑ1
    MyQueue *q = MyQueueEmpty(obj->q1) ? obj->q1 : obj->q2;//如果q1不为空ｐ为q1，那么ｑ就为ｑ2;
    int element = MyQueueFront(p);
    MyQueuePop(p);
    while(!MyQueueEmpty(p)) {//如果不为空
        MyQueuePush(q, element);//就将删除的元素放在另一个中
        element = MyQueueFront(p);
        MyQueuePop(p);
    }
    return element;//记录的是最后一个删除的元素；
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    MyQueue *p = MyQueueEmpty(obj->q1) ? obj->q2 : obj->q1;
    MyQueue *q = MyQueueEmpty(obj->q1) ? obj->q1 : obj->q2;
    int element;
    while(!MyQueueEmpty(p)) {//同删除操作
        element = MyQueueFront(p);
        MyQueuePop(p);
        MyQueuePush(q, element);//记录最后一个元素
    }
    return element;//将最后一个元素返回
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return MyQueueEmpty(obj->q1) && MyQueueEmpty(obj->q2);
}

void myStackFree(MyStack* obj) {
    if(obj == NULL) return;
    MyQueueFree(obj->q1);
    MyQueueFree(obj->q2);
    return;
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
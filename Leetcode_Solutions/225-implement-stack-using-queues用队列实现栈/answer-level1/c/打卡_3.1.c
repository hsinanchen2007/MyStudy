### 解题思路
    创建两个队列qa和qb。
    push时将数据都放在非空的队列中。
    pop时将非空队列中除最后一个元素的数据都存储到空队列中，然后记录非空队列的最后一个数据（即为需要返回的结果），再将非空队列的最后一个元素也pop出来。
    top操作需要返回最后进入队列的元素，但无需改变队列的内容，直接返回非空队列的back()
    empty直接使用队列的判断方法即可。

### c++代码
class MyStack {
private:
    queue<int> qa;
    queue<int> qb;

public:
    /** Initialize your data structure here. */
    MyStack() {
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        if(qa.empty()){
            qb.push(x);
        }else{
            qa.push(x);
        }
        
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int res;
        if(qa.empty()){
            while(qb.size()>1){
                qa.push(qb.front());
                qb.pop();
            }
            res = qb.front();
            qb.pop();
        }else{
            while(qa.size()>1){
                qb.push(qa.front());
                qa.pop();
            }
            res = qa.front();
            qa.pop();
        }
        return res;
    }
    
    /** Get the top element. */
    int top() {
        if(qa.empty()){
            return qb.back();
        }else{
            return qa.back();
        }
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return (qa.empty() && qb.empty())?true:false;
    }
};

### C代码
#define MAX 20000

typedef struct {
    int* queue;
    int head;
    int tail;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack* res = (MyStack*)malloc(sizeof(MyStack));
    res->queue = (int*)malloc(sizeof(int)*MAX);
    res->head = -1;
    res->tail = -1;
    return res;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    obj->tail = (obj->tail+1)%MAX;
    obj->queue[obj->tail] = x;
    if(obj->head==-1){
        obj->head = 0;
    }
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    if(obj->tail==obj->head){
        int res = obj->queue[obj->tail];
        obj->tail = -1;
        obj->head = -1;
        return res;
    }
    int res = obj->queue[obj->tail--];
    return res;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return obj->queue[obj->tail];
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return obj->head==-1?true:false;
}

void myStackFree(MyStack* obj) {
    free(obj->queue);
    free(obj);
}
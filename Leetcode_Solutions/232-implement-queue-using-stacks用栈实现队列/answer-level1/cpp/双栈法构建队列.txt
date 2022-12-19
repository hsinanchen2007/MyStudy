双栈法构建队列：1）先编写一个工具函数，实现两个栈（一空一实）数据的转移，效果是原来实栈变为空，空栈变为实，且数据上下倒置。2）对于push（）和empty()函数，直接调用栈的对应函数即可（都是O（1）的复杂度）。3）对于peek()函数，需要先调用工具函数，q然后取实栈栈顶元素保存；不要忘了还要把栈还原回去，所以再调用一次工具函数；返回保存的元素（时间和空间复杂度都是O(N)）。4）对pop()函数，与peek()函数类似，只是在保存栈顶元素后，需要弹出（时间和空间复杂度都是O(N)）。

结果：17/17  通过，4ms（77.62），8.8MB(71.28)
```
//把p1中的数据转移到p2中
void change_stack_value(stack<int> *p1,stack<int> *p2){
    int k=p1->size();
    for(int i=0;i<k;i++){
        p2->push(p1->top());
        p1->pop();
    } 
}

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        obj= new stack<int>;        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        obj->push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        stack<int> *temp_stack=new stack<int>;
        change_stack_value(obj,temp_stack);
        int temp=temp_stack->top();
        temp_stack->pop();
        change_stack_value(temp_stack,obj);
        return temp;        
    }
    
    /** Get the front element. */
    int peek() {
        stack<int> *temp_stack=new stack<int>;
        change_stack_value(obj,temp_stack);
        int temp=temp_stack->top();
        change_stack_value(temp_stack,obj);
        return temp;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return obj->empty();
    }
private:
    stack<int> *obj;
};
```

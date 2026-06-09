### 解题思路
两个队列，一个push队列，一个pop队列

pop：直接pop队列弹出就可以

push：1.先放进push队列 2.把pop队列的全部拉过来push队列 3.把push队列的再拉回pop队列
其实思想就是：新的元素通过这样“插队”，通过上面三步，最终插队在pop队列最前面

### 代码

```cpp
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        //1.先放进push队列
        queue_push->push(x);
        //2.把pop队列的全部拉过来push队列
        while(!queue_pop->empty()){
            int temp=queue_pop->front();
            queue_push->push(temp);
            queue_pop->pop();
        }
        //3.把push队列的再拉回pop队列（下面直接交换指针）
        queue<int> *temp= queue_pop;
        queue_pop=queue_push;
        queue_push=temp;

    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int temp=queue_pop->front();
        queue_pop->pop();
        return temp;
    }
    
    /** Get the top element. */
    int top() {
        int temp=queue_pop->front();
        return temp;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        if(queue_pop->empty()) 
            return 1;
        else 
            return 0;
    }
private:
    queue<int> *queue_push =new queue<int>() ;
    queue<int> *queue_pop  =new queue<int>();
};


```
### 解题思路
hhh来打卡一波。首先想到队列先进先出，栈先进后出。实例是1234的排列。
用队列的方法来实现栈，首先为了push的简单，我直接沿用了队列的push，这样一来队尾即对应栈顶位置。如果想要实现栈的pop，必须先把队尾前面的所有元素弹出再按顺序添加到队列内，此时队列变成了4123，再用一下队列的pop，序列变成123，这看起来就是完成了栈的pop，至于top操作是一样的，也需要循环一圈。
看了大家的思路，发现在push上偷懒后面pop，top很复杂，先在push把队列倒转，能够方便pop和top。
单队列的这两种思路在时间复杂度上有区别吗，想请教一下！
第一次发布题解，希望有人能看到，希望能坚持61天，加油

### 代码

```cpp
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        iqueue.push(x);
        topp=x;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int temp=0;
        for(int i=0;i<iqueue.size()-1;i++){
            temp=iqueue.front();
            iqueue.pop();
            iqueue.push(temp);
        }
        topp=temp;
        temp=iqueue.front();
        iqueue.pop();
        return temp;
    }
    
    /** Get the top element. */
    int top() {
        int temp=0;
        for(int i=0;i<iqueue.size();i++){
            temp=iqueue.front();
            iqueue.pop();
            iqueue.push(temp);
        }
        return temp;    
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return iqueue.empty();
    }
private :
    queue<int> iqueue;
    int topp=0;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
```
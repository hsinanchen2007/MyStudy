看了别人的答案才知道怎么做，这题目考查的就是队列和栈的基本操作，两者在功能上有少数不同。至于push函数实现方式很显让应该想到一个队列实现吧，可以少写几行代码。
似乎必须另外写数据成员，使用默认构造函数，看题目似乎希望自己写构造函数，算了，不纠结了。
```
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
    
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
    for(int i=0;i<q.size()-1;i++){
        q.push(q.front());
        q.pop();
    }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int val=q.front();
    q.pop();
    return val;
    }
    
    /** Get the top element. */
    int top() {
    return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
    return q.empty();
    }
    private:
    queue<int> q;
};
```

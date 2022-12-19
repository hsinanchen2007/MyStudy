### 分析
- 队列先进先出，栈先进后出
- 可以通过人为修改队列的存储顺序使之成为栈：使用以下的方法
1. 在队列为空时，插入元素至队列末尾等价于队列开头，此时的队列与栈等效。
2. 假设我们拥有一个接口:pop()/front()与栈的pop()/top()等效的队列，如果想要push()插入新元素的时候，把新元素先丢给新的空队列，然后把旧元素搬运过去，这个新队列就也满足栈的接口了。搬运过程中不能改变元素的前后相对位置，而队列的pop(), push()操作天然上是满足这一特性的，迭代调用即可。

### 代码如下

```cpp
class MyStack {
private:
    queue<int> q;
public:
    /** Initialize your data structure here. */
    MyStack() {
        ;
    }
    
    /** Push element x onto stack. */
    void push(int x) {    //把新元素先丢给新的空队列temp，然后把旧队列q的元素搬运过去
        queue<int> temp;
        temp.push(x);
        while(!q.empty()){
            temp.push(q.front());
            q.pop();
        }
        q = temp;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if (q.empty()) return -1;

        int temp = q.front();
        q.pop();
        return temp;
    }
    
    /** Get the top element. */
    int top() {
        if (q.empty()) return -1;
        
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
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
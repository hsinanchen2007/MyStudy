### 解题思路
队列先入先出，栈先入后出
方法一：单队列实现栈
push:为了让最后入的在最开始，推入一个，把其余的放在它后面，用for依次遍历
![image.png](https://pic.leetcode-cn.com/c6ca70b21881bd2de88591f59caec67b342b8ba29daaf3fd0f271ceb250f520a-image.png)
pop:push已经把新入元素放入队头，直接pop即可
empty、top略
方法二：双队列实现栈
push:照常push
pop:把原队列元素按顺序pop/暂存到另一个队列，pop出最后一个元素后再根据暂存队列还原原队列
![image.png](https://pic.leetcode-cn.com/b4d083c29d730514f2d40f57d1d7d3b47054eac81452ae59afd422ab3c5add91-image.png)
注意：
    **q1 = q2为指针交换**
### 代码

```cpp
class MyStack {
public:
    //单链表实现
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        int size = q.size();
        q.push(x);
        int tmp;
        for(int i = 0; i < size; i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int tmp = q.front();
        q.pop();
        return tmp;
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

```cpp
class MyStack {
//双队列实现栈
public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        pushQueue.push(x);
        topValue = x;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        while(pushQueue.size()>1){
            topValue = pushQueue.front();
            popQueue.push(topValue);
            pushQueue.pop();
        }
        int result = pushQueue.front();
        pushQueue.pop();
        queue<int> tmp = pushQueue;
        pushQueue = popQueue;
        popQueue = tmp;
        return result;
    }
    
    /** Get the top element. */
    int top() {
        return topValue;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return pushQueue.empty();
    }

private:
    queue<int> pushQueue;
    queue<int> popQueue;
    int topValue;
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
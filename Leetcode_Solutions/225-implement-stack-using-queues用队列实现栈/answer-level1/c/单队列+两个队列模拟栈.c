思路：单队列要实现先进后出的操作，必须在入队列中的操作的时候倒转顺序，变成先进后出的顺序
```
class MyStack {
public:
    queue<int> Q;
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        int size=Q.size();
        Q.push(x);
        while(size--){
            int tmp=Q.front();
            Q.pop();
            Q.push(tmp);
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int tmp=Q.front();
        Q.pop();
        return tmp;
    }
    
    /** Get the top element. */
    int top() {
        return Q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return Q.size()==0;
    }
};
```

思路：
两个队列的思想是，一个做数据队列一个做辅助队列，每次入栈的时候，都是先把元素放入数据队列中然后辅助队列依次放入数据队列中，实现了先进后出的操作
```
class MyStack {
public:
    // 需要两个队列
    queue<int> q1;
    queue<int> q2;
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        // 元素每次都是装入空的队列，并将另一个队列的元素加入这个队列
        if (q1.empty()) {
            q1.push(x);
            while(!q2.empty()) {
                int temp = q2.front();
                q1.push(temp);
                q2.pop();
            }
        }
        else {
            q2.push(x);
            while(!q1.empty()) {
                int temp = q1.front();
                q2.push(temp);
                q1.pop();
            }
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if (q1.empty()) {
            int res = q2.front();
            q2.pop();
            return res;
        }
        else {
            int res = q1.front();
            q1.pop();
            return res;
        }
    }
    
    /** Get the top element. */
    int top() {
        if (q1.empty()) {
            int res = q2.front();
            return res;
        }
        else {
            int res = q1.front();
            return res;
        }
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        if (q1.empty() && q2.empty()) 
            return true;
        else
            return false;
    }
};


```

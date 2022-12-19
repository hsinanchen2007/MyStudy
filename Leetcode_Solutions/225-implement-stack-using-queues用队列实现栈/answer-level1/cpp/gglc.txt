**题解1：**
	1. 用2个stack，push & top的复杂度为O(1)，pop的复杂度为O(n)
	2. 注意pop的时候，_top变量的处理
```
class MyStack {
public:
    queue<int> q;
    int _top;
    /** Initialize your data structure here. */
    MyStack() {
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        // int len = q.size();
        // queue<int> tmp;
        q.push(x);
        _top = x;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        queue<int> tmp;
        int len = q.size();
        int curr = q.front();
        for(int i =0 ; i < len-1 ; i++){
            curr = q.front();
            q.pop();
            tmp.push(curr);
        }
        q = tmp;
        int ret = _top;
        _top = curr;
        return ret;
    }
    
    /** Get the top element. */
    int top() {
        return _top;
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

题解2：
	1. 单个队列用implace的方式就可以实现
	2. 在push的时候：
        1. 先将第一个元素入列
		2. 将最后一个元素以外的元素出列后重新入列
	3. pop() & top()
        1. 直接出列 & 栈顶元素

```
class MyStack {
public:
    queue<int> q;
    /** Initialize your data structure here. */
    MyStack() {
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        // int len = q.size();
        // queue<int> tmp;
        q.push(x);
        for(int i = 0; i < q.size() -1 ;i++){
            q.push(q.front());
            q.pop();
        }        
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int ret = q.front();
        q.pop();
        return ret;
    }
    
    /** Get the top element. */
    int top() {
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


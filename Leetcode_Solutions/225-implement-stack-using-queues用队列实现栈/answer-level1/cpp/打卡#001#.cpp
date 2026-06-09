单队列实现, 入栈O(n), 出栈O(1).c++
```
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        /*单队列实现:
         *入栈时将队列进行反转
         *-----------------------------
         *que.front()        que.back()
         *-----------------------------
         *stack.top()
         */
        int n = que.size();
        que.push(x);
        for(int i = 0; i < n; i++){
            //即将队头插入队尾
            que.push(que.front());
            //再将队头删掉
            que.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int temp = top();
        que.pop();
        return temp;
    }
    
    /** Get the top element. */
    int top() {
        return que.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return que.empty();
    }
private:
    queue<int> que;
};
```

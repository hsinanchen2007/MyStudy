### 解题思路
此处撰写解题思路

### 代码

```cpp
class MyStack {

    public:
        /** Initialize your data structure here. */
        MyStack() {

        }
        
        /** Push element x onto stack. */
        void push(int x) {
            queue_push.push(x);
            top_value=x;
        }
        
        /** Removes the element on top of the stack and returns that element. */
        int pop() {
            while(queue_push.size()>1){
                top_value=queue_push.front();
                queue_pop.push(top_value);
                queue_push.pop();
            }
            int result = queue_push.front();
            queue_push.pop();
            // swap
            queue<int> temp = queue_push;
            queue_push = queue_pop;
            queue_pop = temp;
            return result;

        }
        
        /** Get the top element. */
        int top() {
            return top_value;
        }
        
        /** Returns whether the stack is empty. */
        bool empty() {
            return queue_push.empty();
        }
    private:
        queue<int> queue_push;
        queue<int> queue_pop;
        int top_value;

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
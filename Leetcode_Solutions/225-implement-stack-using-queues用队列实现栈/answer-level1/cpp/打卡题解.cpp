### 解题思路
打卡打卡

### 代码

```cpp
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        stack.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int nowfront = stack.front();
        int nowback = stack.back();
        vector<int> list;
        while(!stack.empty()){
            list.push_back(stack.front());
            stack.pop();
        }
        for(int i=0;i<list.size()-1;++i){
            stack.push(list[i]);
        }
        return list[list.size()-1];
    }
    
    /** Get the top element. */
    int top() {
        if(stack.empty()){
            return -1;
        }else{
            return stack.back();
        }
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        if(stack.empty()){
            return true;
        }else{
            return false;
        }
    }
private:
    queue<int> stack;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
```![20200301224724.png](https://pic.leetcode-cn.com/cf786452bb0606a3ef71eef25f37feb763305ccbce5e96183e24442ee18d52a6-20200301224724.png)

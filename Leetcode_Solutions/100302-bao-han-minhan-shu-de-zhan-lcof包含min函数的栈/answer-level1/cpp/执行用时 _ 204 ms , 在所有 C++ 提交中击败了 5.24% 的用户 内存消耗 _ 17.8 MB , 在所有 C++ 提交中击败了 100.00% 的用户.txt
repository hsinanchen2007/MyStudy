### 解题思路
用多一个vector来接收数字，然后求最小值，注意不能用sort函数，这样会改变栈的排列顺序

### 代码

```cpp
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        q.push(x);
        arr.push_back(x);
        minn = arr.front();
    }
    // -2 0
    void pop() {
         q.pop();
         arr.pop_back();
         minn = arr.front();
    }
    
    int top() {
         return q.top();
    }
    
    int min() {
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] < minn){
                minn = arr[i];
            }
        }
        return minn;
    }
    stack<int> q;
    vector<int> arr;
    int minn;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
```
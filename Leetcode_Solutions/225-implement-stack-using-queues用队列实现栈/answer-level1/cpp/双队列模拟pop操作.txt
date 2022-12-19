### 解题思路
此题比较简单，思路如下：
+ push操作直接将元素压入队列中。
+ top操作直接返回队列最后一个元素
+ empty操作判断队列大小是否为0
+ pop操作因为queue没有提供弹出最后一个元素的功能，所以用一个辅助队列来帮助弹出。


### 代码

```cpp
class MyStack {
public:
    queue<int> data;
    queue<int> temp;
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        data.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        while(data.size()!=1) {
            temp.push(data.front());
            data.pop();
        }
        int res=data.front();
        data.pop();
        while(temp.size()!=0){
            data.push(temp.front());
            temp.pop();
        }
        return res;
    }
    
    /** Get the top element. */
    int top() {
        return data.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return data.size()==0;
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
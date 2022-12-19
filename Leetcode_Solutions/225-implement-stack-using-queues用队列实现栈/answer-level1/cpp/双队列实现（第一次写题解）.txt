### 解题思路
每次先向queue in中加入元素，加入后将Out中元素移入in，交换in和 out，举个栗子：比如向队列中依次加入 1 ，2 .
加入1时：
in ：1
out: 
交换:
in: 
out : 1

加入2时：
in ：2,1
out: 
交换
in: 
out : 2,1

### 代码

```cpp
class MyStack {
public:
    queue<int> in;
    queue<int> out;
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        in.push(x);
        while(!out.empty()){
            in.push(out.front());
            out.pop();
        }
        swap(in, out);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int a = out.front();
        out.pop();
        return a;
    }
    
    /** Get the top element. */
    int top() {
        return out.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return in.empty()&&out.empty();
    }
};
```
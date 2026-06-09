### 解题思路
1. 如队列in是3->2->1  1位front端。
2. push时正常操作；
3. top：使得in剩下最后一个3并保存tmp，此时in.size()==1, 其余push进去ou中，然后再把剩下的in的一个push进去ou，再从ou压回去in
4. pop: 思路跟上面其实完全一样。处理3的时候pop了就行不需要再压进去ou了

### 代码

```cpp
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        in.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        while(in.size()!=1){
            ou.push(in.front());
            in.pop();
        }
        int tmp = in.front();
        in.pop();
        while(!ou.empty()){
            in.push(ou.front());
            ou.pop();
        }
        return tmp;
    }
    
    /** Get the top element. */
    int top() {
        while(in.size()!=1){
            ou.push(in.front());
            in.pop();
        }
        int tmp = in.front();
        in.pop();
        ou.push(tmp);
        while(!ou.empty()){
            in.push(ou.front());
            ou.pop();
        }
        return tmp;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return ou.empty() && in.empty();
    }
private:
    queue<int> in;
    queue<int> ou;
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
### 解题思路
用队列实现栈，需要建立一个队列和一个辅助队列

### 代码

```cpp
class MyStack {
private:
    queue<int> q1;
public:
    MyStack() {

    }
    
    //正常加入队列
    void push(int x) {
        q1.push(x);
    }
    
    //将队列中的元素全部弹出到辅助队列中，只剩最后一个，记录他
    int pop() {
        queue<int>q2;
        while(q1.size()>1){
            q2.push(q1.front());
            q1.pop();
        }
        int res=q1.front();
        q1=q2;
        return res;
    }   

    //弹出前面的元素只剩最后一个，辅助队列用于记录和恢复队列
    int top() {
        queue<int>q2(q1);
        while(q1.size()>1){
            q1.pop();
        }
        int res=q1.front();
        q1=q2;
        return res;
    }
    
    bool empty() {
        return q1.empty();
    }
};

```
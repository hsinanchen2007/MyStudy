### 解题思路
此处撰写解题思路

### 代码

```cpp
class MyQueue {
stack<int> outPutStack;// 输入栈
    stack<int> inPutStack;// 输出栈
    void checkout() {
       if (outPutStack.size() == 0) {
            while (inPutStack.size() != 0) {
                outPutStack.push(inPutStack.top());
                inPutStack.pop();
            };
        }
    };
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
      
    }
    
    /** 将一个元素放入队列的尾部 */
    void push(int x) {
        inPutStack.push(x);
    }
    
    /** 从队列首部移除元素 */
    int pop() {
        checkout();
        int i = outPutStack.top();
        outPutStack.pop();
        return i;
    }
    
    /** 返回队列首部的元素 */
    int peek() {
        checkout();
        return outPutStack.top();
    }
    
    /** 返回队列是否为空 */
    bool empty() {
       checkout();
        return outPutStack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
```
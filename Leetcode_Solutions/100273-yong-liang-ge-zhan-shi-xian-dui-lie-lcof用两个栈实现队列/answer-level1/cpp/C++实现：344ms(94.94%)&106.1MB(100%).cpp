### 解题思路
栈1用来储存刚加进来的数据，栈2用来按queue的顺序储存数据，两个栈的数量之和是总的现有数据数量。
跟官方题解不同的是，这个只需要倒腾一次而不用两次，效率更高一点点。
每次调用deleteHead的时候才会去判断是否需要倒腾。如果栈2空了且栈1非空，就把栈1倒腾到栈2.如果两个都空自然返回-1.

然后结果就是
![image.png](https://pic.leetcode-cn.com/cfeb929effb07f4a5032f5823368e409d1f38ba9736d78a8524e2457a4fd24dd-image.png)


### 代码

```cpp
class CQueue {
private:
    stack<int> *stack1; //store initial data list;
    stack<int> *stack2; //store data queue;
public:
    CQueue() {
        stack1 = new stack<int>;
        stack2 = new stack<int>;
    }
    
    void appendTail(int value) {
        this->stack1->push(value);
    }
    
    int deleteHead() {
        if(this->stack2->empty()){
            if(this->stack1->empty()) return -1;
            else{
                while(!this->stack1->empty()){
                    this->stack2->push(this->stack1->top());
                    this->stack1->pop();
                }
            }
        }
        int result = this->stack2->top();
        this->stack2->pop();
        return result;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
```
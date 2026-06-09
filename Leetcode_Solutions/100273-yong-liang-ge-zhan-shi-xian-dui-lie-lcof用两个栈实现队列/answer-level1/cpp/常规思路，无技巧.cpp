### 解题思路
思路非常常规，第一遍觉得只要在删除末尾元素的时候，将两个堆栈反序就可以了，发现在append的时候还是不过。坑。

### 代码

```cpp
class CQueue {
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        if(value_.empty()) {
            while(!s2_.empty()) {
                auto top = s2_.top();
                value_.push(top);
                s2_.pop();
            }
        }
        value_.push(value);
        // 重构堆栈数据结构，FIFO
    }
    
    int deleteHead() {
        // 完全重置两个堆栈
        while(!value_.empty()) {
            s2_.push(value_.top());
            value_.pop();
        }

        if(s2_.empty()) {
            return -1;
        }

        auto top = s2_.top();
        s2_.pop();

        return top;
    }
private:
    stack<int> value_;
    stack<int> s2_;
};
```
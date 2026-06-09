### 解题思路
此处撰写解题思路

### 代码

```cpp
class CQueue {
public:
    CQueue() {

    }
    void appendTail(int value) {
        std::stack<int> temp_stack;
        while(!_data.empty())
        {
            temp_stack.push(_data.top());
            _data.pop();
        }
        temp_stack.push(value);
        while(!temp_stack.empty())
        {
            _data.push(temp_stack.top());
            temp_stack.pop();
        }
    }  
    int deleteHead() {
        if(_data.empty()) return -1;
        int x=_data.top();
        _data.pop();
        return x;
    }
private:
    std::stack<int> _data;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
```
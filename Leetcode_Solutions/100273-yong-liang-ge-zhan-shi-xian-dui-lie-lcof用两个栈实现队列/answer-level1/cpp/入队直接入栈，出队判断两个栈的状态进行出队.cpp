### 解题思路
此处撰写解题思路

### 代码

```cpp
class CQueue {
public:
    CQueue() {
        
    }
    
    void appendTail(int value) {
        stack1.push(value);
    }
    
    int deleteHead() {
        if(stack1.empty()&&stack2.empty())
            return -1;
        int temp=0;
        if(!stack2.empty()){
            temp=stack2.top();
            stack2.pop();
        }
        else{
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
            temp=stack2.top();
            stack2.pop();
        }
        return temp;
           
    }
private:
std::stack<int> stack1;
std::stack<int> stack2;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
```
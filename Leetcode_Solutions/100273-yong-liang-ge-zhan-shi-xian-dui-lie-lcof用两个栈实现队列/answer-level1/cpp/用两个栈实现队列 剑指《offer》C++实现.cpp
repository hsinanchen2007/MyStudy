### 解题思路
剑指《offer》C++实现

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
        // 先检查stack2是否为空，如果stack2为空，需要stack1传过来
        if(stack2.empty()){
            if(stack1.empty()) return -1;
            while(!stack1.empty()){
                // int& data = stack1.top();
                // stack2.push(data);
                // stack1.pop();
                stack2.push(stack1.top());          // 将stack1栈顶元素压栈到stack2,以实现队列功能
                stack1.pop();
                
            }
        }

        // 因为stack2中的元素比stack1中的元素先进去，所以当stack2中有元素的时候，可以直接出栈
        // 反证法：如果stack2中的元素不比stack1中的元素靠前，那么当stack2中有元素时，stack1中又进来一个元素，这时如果先把stack1中的栈顶元素移动到stack2中时，就实现了后进先出了，矛盾

        // if(!stack2.empty())
        int& head = stack2.top();
        stack2.pop();
        return head;
    }
private:
    stack<int> stack1;
    stack<int> stack2;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
```
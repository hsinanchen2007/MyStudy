### 解题思路
注意：不必在解题过程中，一直保持s1或s2是原队列的整体形式，保证出队顺序及判空，便能保证答案正确，此时是复杂度最低情况。
stack2空说明，所有在stack1中元素之前入队的元素都已经出队
在stack2不空的情形下，res即此时该出队的元素
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
        if(stack1.empty() && stack2.empty()) return -1;
        if(stack2.empty()) //stack2空说明，所有在stack1中元素之前入队的元素都已经出队
        {
            while(!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        int res = stack2.top(); //在stack2不空的情形下，res即此时该出队的元素
        stack2.pop();
        return res;
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
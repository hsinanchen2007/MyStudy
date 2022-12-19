执行用时 :4 ms, 在所有 C++ 提交中击败了84.34%的用户
内存消耗 :8.9 MB, 在所有 C++ 提交中击败了36.01%的用户

```
class MyQueue {
public:
    /** Initialize your data structure here. */
    //使用两个栈来实现队列
    stack<int> left;
    stack<int> right;
    
    MyQueue() {//初始化
        
        if(!left.empty()){
            
            while(!left.empty())
                left.pop();
        }
        if(!right.empty()){
            
            while(!right.empty())
                right.pop();
        }

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        
        if(right.empty()){//如果右栈为空，则直接压入左栈
            
            left.push(x);
        }
        else{
            
            while(!right.empty()){//如果右栈不为空，先逐一搬空到左栈，然后在把输入压到左栈
                
                int temp = right.top();
                right.pop();
                left.push(temp);
            }
            
            left.push(x);
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        
        if(!right.empty()){//如果右栈不为空，则直接在右栈pop栈头并返回
            
            int temp = right.top();
            right.pop();
            
            return temp;
        }
        else if(left.empty() && right.empty())//如果左右栈都为空，则返回false
            return false;
        
        else{
            
            while(!left.empty()){//如果左栈不为空，则先逐一pop搬到右栈，再pop掉右栈的栈头并返回
                
                int temp = left.top();
                left.pop();
                right.push(temp);               
            }
            
            int temp = right.top();
            right.pop();
            
            return temp;
        }
        
    }
    
    /** Get the front element. */
    int peek() {
        
        if(!right.empty()){//如果右栈不为空，则直接返回右栈栈首
            
            int temp = right.top();
            
            return temp; 
        }
        else if(left.empty() && right.empty())//如果左右栈都为空，则返回false
            return false;
        
        else{
            
            while(!left.empty()){//如果左栈不为空，则逐一搬空左栈元素到右栈，再返回右栈栈首
                
                int temp = left.top();
                left.pop();
                right.push(temp);
            }
            
            int temp = right.top();
            
            return temp;
        }
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        
        if(left.empty() && right.empty())
            return true;
        
        else
            return false;
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

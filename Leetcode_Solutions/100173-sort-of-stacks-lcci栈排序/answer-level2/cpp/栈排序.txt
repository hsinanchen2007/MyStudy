### 解题思路

方法：借用辅助栈temp来实现栈s的排序
思路：1.针对push操作，如果栈s不为空“!s.empty()”并且栈顶元素小于val “s.top()<val”，则将栈顶元素压入栈temp，并将s栈顶元素弹出,直到不满足两个要求为止；若栈s为空，或者“s.top()>=val”则将val压入栈s中;最后将栈temp的元素一次压入栈s中。

### 代码

```cpp
class SortedStack {
public:
    SortedStack(){
    
    }
    
    void push(int val){       
        while(!s.empty()&&s.top()<val){
            temp.push(s.top());
            s.pop();
        }
        if(s.empty()||s.top()>=val){
            s.push(val);
        }
        while(!temp.empty()){
            s.push(temp.top());
            temp.pop();
        }
    }
    void pop(){
        if(s.empty()) return;
        s.pop();
    }
    int peek(){
        if(s.empty()){
            return -1;
        }else{
            return s.top();
        }
        
    }
    bool isEmpty(){
        return s.empty();
    }
private:
    stack<int> s;
    stack<int> temp;
};

/**
 * Your SortedStack object will be instantiated and called as such:
 * SortedStack* obj = new SortedStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->isEmpty();
 */
```
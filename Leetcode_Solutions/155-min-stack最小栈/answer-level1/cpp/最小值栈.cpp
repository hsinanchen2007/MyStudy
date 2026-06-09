
数据栈和最小栈同步
-------------------

```cpp
class MinStack {
public:

    MinStack() {

    }
    
    void push(int x) {
        dataStack.push(x);
        if(miniStack.empty()){
            miniStack.push(x);
        }else{
            int min=miniStack.top();
            if(min>=x){
                miniStack.push(x);
            }
        }
    }
    
    void pop() {
        if( dataStack.top()==miniStack.top()){
            dataStack.pop();
            miniStack.pop();
        }else{
            dataStack.pop();
        }
    }
    
    int top() {
        return dataStack.top();
    }
    
    int getMin() {
        return miniStack.top();
    }
private:
    stack<int> dataStack;
    stack<int> miniStack;
};


```
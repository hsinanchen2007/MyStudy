采用2个栈，data栈用来保存数据，MinData栈用来保存最小值。
```
class MinStack {
private:
    stack<int> data;
    stack<int> MinData;
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        if(data.empty()){ //如果栈为空，把该值push到MinData栈
            MinData.push(x);
        }else if(x <= MinData.top()){ //等号是为了处理重复插入相同的最小值元素情况
            MinData.push(x);
        }
        data.push(x);
    }
    
    void pop() {
        if(data.top() == MinData.top()) MinData.pop(); 
        data.pop();
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return MinData.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
```

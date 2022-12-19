### 解题思路
C++ vector解法
### 代码

```cpp
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        tp=-1;
        size=0;
    }
    
    void push(int x) {
      stack.push_back(x);
      ++tp;
      ++size;
    }
    
    void pop() {
        if(size<=0||tp<0)
        return ;
          vector<int>::iterator it=stack.end();
          stack.erase((--it));
          --size;
          --tp;
    }
    
    int top() {
        if(size<=0||tp<0)
        return  0;
        return stack[tp];
        
    }
    
    int getMin() {
        if(tp<0||size<=0){
            return 0;
        }
        if(size==1||tp==0)
        return stack[tp];

        int min=stack[tp];
        for(auto k:stack){
            if(k<min)
            min=k;
        }
        return min;
    }
    private:
    int tp;
    int size;
    vector<int> stack;
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
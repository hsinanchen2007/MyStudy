### 解题思路
利用两个栈s1,s2，其中s1存放排序数据，
当执行push()时，若s1.top()<val,将所有小于val的元素放入s2,再将val压入s1中，最后将s2中的元素放入s1中，实现s1的排序push

### 代码

```cpp
class SortedStack {
public:
    stack<int>s1;
    stack<int>s2;
    SortedStack() {

    }
    
    void push(int val) {
        while(!s1.empty()&&s1.top()<val){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(val);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    void pop() {
        if(!s1.empty()){
            s1.pop();
        }
    }
    
    int peek() {
      if(!s1.empty()){
            return s1.top();
        }
        return -1;
    }
    
    bool isEmpty() {
        return s1.empty();
    }
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
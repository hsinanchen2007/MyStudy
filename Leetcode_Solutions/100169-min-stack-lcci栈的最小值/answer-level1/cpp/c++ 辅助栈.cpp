### 解题思路
构建两个栈，一个栈为主栈，存储数据；另一个栈为副栈，存当前数据的最小值。
在每一次push的时候，主栈正常push，压入数据；
副栈需要执行一次判断，如果当前值小于顶点值，则说明压入新数据后，最小值还是之前的值
反之则当前值是最小值，依次类推即可。
拿样例来说明的话为：
push:-2,0,-3;
主栈：-2,0,-3;
副栈：-2,-2,-3.
这样的话，就可以得到每一个节点的当前最小值了。

### 代码

```cpp
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        main_stk.push(x);
        if(help_stk.empty()) help_stk.push(x);
        else {
            if(x < help_stk.top()){
                help_stk.push(x);
            }else{
                int temp = help_stk.top();
                help_stk.push(temp);
            }
        }
    }
    
    void pop() {
        main_stk.pop();
        help_stk.pop();
    }
    
    int top() {
        return main_stk.top();
    }
    
    int getMin() {
        return help_stk.top();
    }
private:
    stack<int> main_stk;
    stack<int> help_stk;
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
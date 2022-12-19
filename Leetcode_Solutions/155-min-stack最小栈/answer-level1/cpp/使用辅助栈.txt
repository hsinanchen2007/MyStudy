### 解题思路
执行用时 :
28 ms, 在所有 C++ 提交中击败了97.34%的用户
内存消耗 :17.1 MB, 在所有 C++ 提交中击败了
13.20%的用户



### 代码

```cpp
class MinStack 
{
private:
    stack<int>data;
    stack<int>min;
public:
    /** initialize your data structure here. */
    MinStack() 
    {
        
    }
    
    void push(int x) 
    {
        data.push(x);
        if(min.size()== 0 || x < min.top())
        {
            min.push(x);
        }
        else
        {
            min.push(min.top());
        }
    }
    
    void pop() 
    {
        data.pop();
        min.pop();
    }
    
    int top() 
    {
        return data.top();
    }
    
    int getMin() 
    {
        return min.top();
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
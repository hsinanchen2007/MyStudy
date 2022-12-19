### 解题思路
好的，这道题比较简单，我们就说两点我当时碰到的问题。
1. void和int函数的返回值，像这里，void push()和void pop()就是直接stk.poop()。但是像int top()就要return stk.top()。
2. 在push()函数中，一开始写得是这样——
```c++
void push(int x)
    {
        stk.push(x);
        if (minstk.empty() or x <= minstk.top())
        {
            minstk.push(x);
        }
    }
```
这样子写执行错误了，是因为少考虑了一种情况，如果存储最小值的那个栈minStk的栈顶元素一直是mininum的，上述写法，会导致minStk这个栈永远只有一个元素。但是我们要实现的最小值栈，是要存储普通栈stk中每输入一个元素，都要记录当前这个输入元素本身及其前面的元素中的最小值，所以就算最小值一直是1，minStk中的元素数量也要跟stk普通栈中的元素数量是一样的。所以上述写法错误。
应该用下面的这个写法——
```c++
void push(int x) 
    {
        stk.push(x);
        if (minStk.empty() )
        {
            minStk.push(x);
        }
        else
        {
            int minT = minStk.top();
            minStk.push(x < minT ? x : minT);
        }
    }
```

### 代码

```cpp
class MinStack 
{
public:
    stack<int> stk;
    stack<int> minStk;

    /** initialize your data structure here. */
    MinStack() {}
    
    void push(int x) 
    {
        stk.push(x);
        if (minStk.empty() )
        {
            minStk.push(x);
        }
        else
        {
            int minT = minStk.top();
            minStk.push(x < minT ? x : minT);
        }
    }
    
    void pop() 
    {
        stk.pop();
        minStk.pop();
    }
    
    int top() 
    {
        return stk.top();
    }
    
    int getMin() 
    {
        return minStk.top();
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
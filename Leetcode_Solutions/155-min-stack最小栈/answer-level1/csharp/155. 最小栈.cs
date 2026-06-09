### 解题思路
使用一个栈存储最小值，每次要入栈值时，如果最小栈不存在值，则同时将此值直接存入最小栈，否则比较入栈的值是否小于等于最小栈的栈顶的值，如果成立，则同时在最小栈Push该值，每次出栈时，比较该值时候等于最小栈的栈顶的值，如果相等，则同时在最小栈顶端移除该值。
获取最小值时直接弹出最小栈的栈顶即可。

### 代码

```csharp
public class MinStack
{
    Stack<int> stack = new Stack<int>();
    Stack<int> minStack = new Stack<int>();

    /** initialize your data structure here. */
    public MinStack()
    {
    }

    public void Push(int x)
    {
        if (minStack.Count == 0)
        {
            minStack.Push(x);
        }
        else
        {
            if (minStack.Peek() >= x)
            {
                minStack.Push(x);
            }
        }

        stack.Push(x);
    }

    public void Pop()
    {
        if (stack.Count == 0) return;
        var value = stack.Pop();
        if (value == minStack.Peek())
        {
            minStack.Pop();
        }
    }

    public int Top()
    {
        return stack.Peek();
    }

    public int GetMin()
    {
        return minStack.Peek();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.Push(x);
 * obj.Pop();
 * int param_3 = obj.Top();
 * int param_4 = obj.GetMin();
 */
```
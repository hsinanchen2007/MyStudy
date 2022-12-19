### 解题思路
此处撰写解题思路

### 代码

```csharp
public class MinStack {
    private Stack<int> stack;
    private Stack<int> minStack;
    /** initialize your data structure here. */
    public MinStack() {
        minStack = new Stack<int>();
        stack = new Stack<int>();
    }
    
    public void Push(int x) {
        int min = x;
        if(minStack.Any() && x>minStack.Peek())
        {
            min = minStack.Peek();
        }
        stack.Push(x);
        minStack.Push(min);
    }
    
    public void Pop() {
        stack.Pop();
        minStack.Pop();
    }
    
    public int Top() {
        return stack.Peek();
    }
    
    public int GetMin() {
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
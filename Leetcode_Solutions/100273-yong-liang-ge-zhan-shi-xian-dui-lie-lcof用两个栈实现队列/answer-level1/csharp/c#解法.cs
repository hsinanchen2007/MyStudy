### 解题思路


### 代码

```csharp
public class CQueue {
    Stack<int> stack1 = new Stack<int>();
    Stack<int> stack2 = new Stack<int>();
    public CQueue() {

    }
    
    public void AppendTail(int value) {
        stack2.Push(value);
    }
    
    public int DeleteHead() {
        if(stack1.Count <= 0)
        {
            while(stack2.Count > 0)
            {
                int v = stack2.Pop();
                stack1.Push(v);
            }
        }

        return stack1.Count > 0? stack1.Pop(): -1;
    }
}

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue obj = new CQueue();
 * obj.AppendTail(value);
 * int param_2 = obj.DeleteHead();
 */
```
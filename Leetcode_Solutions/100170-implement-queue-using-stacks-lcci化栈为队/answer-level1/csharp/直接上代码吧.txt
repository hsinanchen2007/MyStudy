### 解题思路
直接上代码吧

### 代码

```csharp
public class MyQueue {

    public Stack<int> realStack = new Stack<int>();
    public Stack<int> helpStack = new Stack<int>();

    /** Initialize your data structure here. */
    public MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    public void Push(int x) {
        if (realStack.Count == 0)
        {
            realStack.Push(x);
            return;
        }
        while(realStack.Count > 0)
        {
            helpStack.Push(realStack.Pop());
        }
        realStack.Push(x);
        while(helpStack.Count > 0)
        {
            realStack.Push(helpStack.Pop());
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    public int Pop() {
        return realStack.Pop();
    }
    
    /** Get the front element. */
    public int Peek() {
        return realStack.Peek();
    }
    
    /** Returns whether the queue is empty. */
    public bool Empty() {
        return realStack.Count == 0;
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.Push(x);
 * int param_2 = obj.Pop();
 * int param_3 = obj.Peek();
 * bool param_4 = obj.Empty();
 */
```
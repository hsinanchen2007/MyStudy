### 解题思路
主要难点就在Push函数，需要修改队列中的方向，从而达到栈的效果，入队列的时候借助一个辅助队列，使新数据位于队列尾端，从而达到栈的先入后出的效果

### 代码

```csharp
public class MyStack {

    private Queue<int> q;

    /** Initialize your data structure here. */
    public MyStack()
    {
        q = new Queue<int>();

    }

    /** Push element x onto stack. */
    public void Push(int x)
    {
        var queue = new Queue<int>();
        queue.Enqueue(x);
        foreach (var elemet in q)
        {
            queue.Enqueue(elemet);
        }
        q = queue;
    }

    /** Removes the element on top of the stack and returns that element. */
    public int Pop()
    {
        return q.Dequeue();
    }

    /** Get the top element. */
    public int Top()
    {
        return q.First();
    }

    /** Returns whether the stack is empty. */
    public bool Empty()
    {
        return !q.Any();
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.Push(x);
 * int param_2 = obj.Pop();
 * int param_3 = obj.Top();
 * bool param_4 = obj.Empty();
 */
```
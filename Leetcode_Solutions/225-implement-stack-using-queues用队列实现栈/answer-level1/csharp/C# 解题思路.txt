### 解题思路
开始时主队列为空，
每当我们压入的时候都会零时创建一个队列，让要进来的数字作为临时队列的第一位当作栈顶
假设现在主队列为空，让主队列等于临时队列即可，这时主队列已经按照栈的出入顺序排好，这样进出都不需要再进行排序。
如果不为空，因为已经排序好了，遍历加入临时队列即可
```
public class MyStack {
    Queue<int> queue;
    /** Initialize your data structure here. */
    public MyStack()
    {
        queue = new Queue<int>();
    }

    /** Push element x onto stack. */
    public void Push(int x)
    {
        Queue<int> queueTemp = new Queue<int>();
        queueTemp.Enqueue(x);
        foreach (var elemet in queue)
        {
            queueTemp.Enqueue(elemet);
        }
        queue = queueTemp;
    }

    /** Removes the element on top of the stack and returns that element. */
    public int Pop()
    {
        return queue.Dequeue();
    }

    /** Get the top element. */
    public int Top()
    {
        return queue.First();
    }

    /** Returns whether the stack is empty. */
    public bool Empty()
    {
        return !queue.Any();
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
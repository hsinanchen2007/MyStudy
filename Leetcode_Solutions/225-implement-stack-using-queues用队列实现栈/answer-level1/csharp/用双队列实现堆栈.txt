### 解题思路
Push 在原队列上进队
Pop 需要交换队列，把原队列前n-1个元素进入另一个队列中，剩下一个元素出栈并作为返回值，原队列变成待交换队列
Top 每次Push、Pop保存top的值，常量空间就能明显提升堆栈Top操作的性能，很划算
Empty 返回原队列的元素数量

### 代码

```csharp
public class MyStack {
    private readonly Queue<int> queue1 = new Queue<int>();
    private readonly Queue<int> queue2 = new Queue<int>();
    private bool isInQueue1 = false;
    private int top;
    /** Initialize your data structure here. */
    public MyStack() {
    }

    /** Push element x onto stack. */
    public void Push(int x) {
        var toenqueue = isInQueue1 ? queue1 : queue2;
        toenqueue.Enqueue(x);
        top = x;
    }

    /** Removes the element on top of the stack and returns that element. */
    public int Pop() {
        var outQueue = isInQueue1 ? queue1 : queue2;
        var inQueue = isInQueue1 ? queue2 : queue1;
        isInQueue1 = !isInQueue1;
        int count = outQueue.Count;
        top = 0;
        while (count-- > 1) {
            if (count == 1) top = outQueue.Peek();
            inQueue.Enqueue(outQueue.Dequeue());
        }
        return outQueue.Dequeue();
    }

    /** Get the top element. */
    public int Top() {
        return top;
    }

    /** Returns whether the stack is empty. */
    public bool Empty() {
        int count = isInQueue1 ? queue1.Count : queue2.Count;
        return count <= 0;
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
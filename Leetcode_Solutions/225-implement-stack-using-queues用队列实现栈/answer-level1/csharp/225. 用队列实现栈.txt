### 解题思路
使用一个队列实现栈：只能实现存和取两个操作其中一个时间复杂度为O(1)另一个为O(n)
因为本题有 Pop 和 Top 两个读取操作，所以采取的模式是写入为 O(n),读取为 O(1)
所谓实现栈和O(n)就是在入队或出队时循环前n-1个节点，从队首出队后立即再加入队排在队尾，即实现队反序

### 代码

```csharp
public class MyStack
{
    /* 使用一个队列实现栈：只能实现存和取两个操作其中一个时间复杂度为O(1)另一个为O(n)
        * 因为本题有 Pop 和 Top 两个读取操作，所以采取的模式是写入为 O(n),读取为 O(1)
        * 所谓实现栈和O(n)就是在入队或出队时循环前n-1个节点，从队首出队后立即再加入队排在队尾，即实现队反序
        */
    Queue<int> queue = new Queue<int>();

    /** Initialize your data structure here. */
    public MyStack()
    {
    }

    /** Push element x onto stack. */
    public void Push(int x)
    {
        queue.Enqueue(x);

        for (int index = 0; index < this.queue.Count - 1; index++)
        {
            queue.Enqueue(queue.Dequeue());
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    public int Pop()
    {
        return queue.Count > 0 ? queue.Dequeue() : -1;
    }

    /** Get the top element. */
    public int Top()
    {
        return queue.Count > 0 ? queue.Peek() : -1;
    }

    /** Returns whether the stack is empty. */
    public bool Empty()
    {
        return queue.Count == 0;
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
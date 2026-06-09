### 解题思路

### 代码

```csharp
public class MyStack {

    public Queue<int> myQueue = new Queue<int>();
    public MyStack()
    {

    }

    public void Push(int x)
    {
        //直接放入队列不管
        myQueue.Enqueue(x);
    }

    public int Pop()
    {
        //利用list临时存储队列的消息
        List<int> list = myQueue.ToList<int>();
        while (myQueue.Count > 1)
        {
            myQueue.Dequeue();
        }
        //栈顶元素就是队列的最后一个元素
        int m = myQueue.Dequeue();
        for (int i = 0; i < list.Count - 1; i++)
        {
            myQueue.Enqueue(list[i]);
        }
        //返回最后一个
        return m;
    }

    public int Top()
    {
        List<int> list = myQueue.ToList<int>();
        while (myQueue.Count > 1)
        {
            myQueue.Dequeue();
        }
        //返回最后一个并且把全部元素再放回去
        int m = myQueue.Dequeue();
        for (int i = 0; i < list.Count; i++)
        {
            myQueue.Enqueue(list[i]);
        }
        return m;
    }

    public bool Empty()
    {
        if (myQueue.Count > 0)
        {
            return false;
        }
        return true;
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
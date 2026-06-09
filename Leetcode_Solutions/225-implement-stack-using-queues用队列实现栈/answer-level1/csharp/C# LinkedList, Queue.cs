### 解题思路
LinkedList可以头尾操作

### 代码

```csharp
public class MyStack
{
    LinkedList<int> queue = new LinkedList<int>();


    public MyStack()
    {
    }

    public void Push(int x)
    {
        queue.AddLast(x);
    }

    public int Pop()
    {
        int res = queue.Last();
        queue.RemoveLast();
        return res;
    }

    public int Top()
    {
        return queue.Last();
    }

    public bool Empty() => !queue.Any();  
}

public class MyStack
    {
        Queue<int>  queue1 = new Queue<int>();
        Queue<int>  queue2 = new Queue<int>();
        private int top    = 0;

        public MyStack()
        {
        }

        public void Push(int x)
        {
            top = x;
            queue1.Enqueue(x);
        }

        public int Pop()
        {
            if (queue2.Count != 0)
                return queue2.Dequeue();

            if (queue1.Count == 0)
                return -1;

            foreach (var val in queue1.Reverse())
                queue2.Enqueue(val);
            queue1.Clear();

            return queue2.Dequeue();
        }

        public int Top()
        {
            if (queue2.Count != 0)
                return queue2.Peek();
            return top;
        }

        public bool Empty() => queue1.Count == 0 && queue2.Count == 0;  
    }

```
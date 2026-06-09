### 解题思路
用两个队列实现，外加一个布尔标记当前使用的是哪个队列
- push：如果当前使用的是a队列，则push时往a队列进行入队，如果是b队列则往b队列进行入队
- pop：如果使用的是a队列，则将标记取反，以示将切换到b队列；然后将a队列的值一个个出队，入队到b队列，唯独保留a队列中最后一个值x，x不用入队到b队列。然后将x出队，即弹出；也就是通过出对入队，将原先队列里的最后一个值x扒出来，这个x就是要弹出的值；
- top：同pop，只是原本应该弹出的值x仍然要入队到切换后的队列里，只是先将它的值记录下来，然后入队，最后返回该值；
- empty：就只要取当前所使用的队列的count值是否为0就可以了

### 代码

```csharp
public class MyStack {
        private Queue<int> queueFirst;
        private Queue<int> queueSecond;
        private bool isFirst;
    /** Initialize your data structure here. */
    public MyStack() {
            queueFirst = new Queue<int>();
            queueSecond = new Queue<int>();
    }
    
    /** Push element x onto stack. */
    public void Push(int x) {
            if (isFirst)
            {
                queueFirst.Enqueue(x);
            }
            else
            {
                queueSecond.Enqueue(x);
            }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int Pop() {
            if (isFirst)
            {
                isFirst = false;
                int count = queueFirst.Count;
                if (count < 1)
                {
                    throw new InvalidOperationException("栈下溢");
                }
                for (int i = 0; i < count - 1; i++)
                {
                    queueSecond.Enqueue(queueFirst.Dequeue()); ;
                }
                return queueFirst.Dequeue();
            }
            else
            {
                isFirst = true;
                int count = queueSecond.Count;
                if (count < 1)
                {
                    throw new InvalidOperationException("栈下溢");
                }
                for (int i = 0; i < count - 1; i++)
                {
                    queueFirst.Enqueue(queueSecond.Dequeue()); ;
                }
                return queueSecond.Dequeue();
            }
    }
    
    /** Get the top element. */
    public int Top() {
            if (isFirst)
            {
                isFirst = false;
                int count = queueFirst.Count;
                if (count < 1)
                {
                    throw new InvalidOperationException("栈下溢");
                }
                for (int i = 0; i < count - 1; i++)
                {
                    queueSecond.Enqueue(queueFirst.Dequeue()); ;
                }
                int peak = queueFirst.Dequeue();
                queueSecond.Enqueue(peak);
                return peak;
            }
            else
            {
                isFirst = true;
                int count = queueSecond.Count;
                if (count < 1)
                {
                    throw new InvalidOperationException("栈下溢");
                }
                for (int i = 0; i < count - 1; i++)
                {
                    queueFirst.Enqueue(queueSecond.Dequeue()); ;
                }
                int peak = queueSecond.Dequeue();
                queueFirst.Enqueue(peak); ;
                return peak;
            }
    }
    
    /** Returns whether the stack is empty. */
        public bool Empty()
        {
            return (isFirst ? queueFirst.Count : queueSecond.Count) == 0;
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
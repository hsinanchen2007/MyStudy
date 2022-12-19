### 解题思路
    使用双栈懒惰更新实现队列：栈A用于入栈，栈B用于出栈，当入栈时，B栈所有元素放入A栈，此时在A栈Push插入的值，当出栈时，将A栈所有的值放入B栈，此时B栈的栈顶就是原A栈的栈底，相当于把栈反向，从B栈的栈顶取值即可。
懒惰更新：仅在入栈和出栈之前做两个栈的调整工作，调整之后不做恢复。

### 代码

```csharp
    public class MyQueue
    {
        Stack<int> stackA = new Stack<int>();
        Stack<int> stackB = new Stack<int>();

        /** Initialize your data structure here. */
        public MyQueue()
        {
        }

        /** Push element x to the back of queue. */
        public void Push(int x)
        {
            while (stackB.Count > 0)
            {
                stackA.Push(stackB.Pop());
            }

            stackA.Push(x);
        }

        /** Removes the element from in front of queue and returns that element. */
        public int Pop()
        {
            if (this.Empty())
            {
                return -1;
            }

            while (stackA.Count > 0)
            {
                stackB.Push(stackA.Pop());
            }

            return stackB.Pop();
        }

        /** Get the front element. */
        public int Peek()
        {
            if (this.Empty())
            {
                return -1;
            }

            while (stackA.Count > 0)
            {
                stackB.Push(stackA.Pop());
            }

            return stackB.Peek();
        }

        /** Returns whether the queue is empty. */
        public bool Empty()
        {
            return stackA.Count == 0 && stackB.Count == 0;
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
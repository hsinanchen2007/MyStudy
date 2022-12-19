### 解题思路
此处撰写解题思路
### 代码

```csharp
public class MyStack {

            Queue<int> Q;
            public MyStack()
            {
                Q = new Queue<int>();
            }
            public void Push(int x)
            {
                LinkedList<int> L = new LinkedList<int>();
                L.AddLast(x);
                while (Q.Count != 0)
                    L.AddLast(Q.Dequeue());
                while (L.Count != 0)
                {
                    Q.Enqueue(L.First());
                    L.RemoveFirst();
                }
            }
            public int Pop()
            {
                return Q.Dequeue();
            }
            public int Top()
            {
                return Q.Peek();
            }
            public bool Empty()
            {
                if (Q.Count == 0)
                    return true;
                else
                    return false;
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
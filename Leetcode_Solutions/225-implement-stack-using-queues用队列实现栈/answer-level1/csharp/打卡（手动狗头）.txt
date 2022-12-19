### 解题思路
此处撰写解题思路
使用2个队列，一个tmp作为临时保存在que在push的其他变量，让最新元素可以在队列底部，从而保证先入后出
### 代码

```csharp
public class MyStack
        {

            /** Initialize your data structure here. */
            private Queue<int> que;
            private Queue<int> tmp;
            public MyStack()
            {
                que = new Queue<int>();
                tmp = new Queue<int>();
            }

            /** Push element x onto stack. */
            public void Push(int x)
            {
                while (que.Count > 0)
                {
                    tmp.Enqueue(que.Dequeue());
                }
                que.Enqueue(x);
                while (tmp.Count > 0)
                {
                    que.Enqueue(tmp.Dequeue());
                }
            }

            /** Removes the element on top of the stack and returns that element. */
            public int Pop()
            {
                return que.Count==0?throw new Exception("stack is empty") : que.Dequeue();
            }

            /** Get the top element. */
            public int Top()
            {
                return que.Peek();
            }

            /** Returns whether the stack is empty. */
            public bool Empty()
            {
                return que.Count == 0;
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
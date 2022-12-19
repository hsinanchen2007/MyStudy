**思路1：** 无脑调用现成的实现
```csharp
public class MinStack {

   private Stack<int> myStack;
        public MinStack()
        {
            myStack = new Stack<int>();
        }

        public void Push(int x)
        {
            myStack.Push(x);
        }

        public void Pop()
        {
            myStack.Pop();
        }

        public int Top()
        {
            return myStack.FirstOrDefault();
        }

        public int GetMin()
        {
            return myStack.Min();
        }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.Push(x);
 * obj.Pop();
 * int param_3 = obj.Top();
 * int param_4 = obj.GetMin();
 */
```
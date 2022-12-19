### 解题思路
此处撰写解题思路

    public class MyStack
    {
        List<int> _list = null;
        /** Initialize your data structure here. */
        public MyStack()
        {
            _list = new List<int>();
        }

        //元素X入栈
        /** Push element x onto stack. */
        public void Push(int x)
        {
            _list.Add(x);
        }

        //移除栈顶元素
        /** Removes the element on top of the stack and returns that element. */
        public int Pop()
        {
            if (this.Empty())
            {
                throw new Exception("stack is null");
            }
            int _size = _list.Count();
            int result = _list[_size - 1];
            _list.Remove(result);
            return result;
        }

        //获取栈顶元素
        /** Get the top element. */
        public int Top()
        {
            if (this.Empty())
            {
                throw new Exception("stack is null");
            }
            int _size = _list.Count();
            int result = _list[_size - 1];
            return result;
        }

        //判断栈是否为空
        /** Returns whether the stack is empty. */
        public bool Empty()
        {
            return _list.Count() == 0 ? true : false;
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


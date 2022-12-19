**话不多说，直接上代码：**

    def __init__(self):
        """
        Initialize your data structure here.
        """
        #定义用于存放栈顶的队列（q1）和其他元素的队列（q2）
        import queue as q
        self.q1 = q.Queue()
        self.q2 = q.Queue()

        
    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.q1.put(x)

        
    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        #将先入队的元素放入q2，在取出q1的最后一个数。
        while self.q1.qsize() > 1:
            self.q2.put(self.q1.get())
        res = self.q1.get()
        #交换q1和q2用于下一次操作
        self.q1, self.q2 = self.q2, self.q1
        return res
        

    def top(self) -> int:
        """
        Get the top element.
        """
        #pop后得到top，但要将top重新放入q1
        res = self.pop()
        self.q1.put(res)
        return res

    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return self.q1.empty() and self.q2.empty()
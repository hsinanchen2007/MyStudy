解题思路，用到辅助队列来反转队列中的元素。
```
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.q1 = []    # 输入
        self.q2 = []    # 输出

    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.q1.append(x)
        for i in range(len(self.q1)//2):
            self.q1[i], self.q1[len(self.q1)-1-i] = self.q1[len(self.q1)-1-i], self.q1[i]     # 反转列表
        return self.q1
        

    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        if len(self.q1)!=0:
            for i in range(len(self.q1)):
                self.q2.append(self.q1.pop())
            x = self.q2.pop()
            self.q1 = self.q2
            self.q2 = []
        return x


    def top(self) -> int:
        """
        Get the top element.
        """
        return self.q1[0]


    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        if len(self.q1)==0:
            return True
        else:
            return False


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```


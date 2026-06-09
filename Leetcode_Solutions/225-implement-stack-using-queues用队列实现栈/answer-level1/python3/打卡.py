### 解题思路
此处撰写解题思路

用Python，都不需要用到两个队列，一个队列反转之类的思路，如果面试官看到这种解法，会挨打吗

def __init__(self):
        """
        Initialize your data structure here.
        """
        self._que1 = []
        

    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self._que1.append(x)
        

    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        return self._que1.pop()
        

    def top(self) -> int:
        """
        Get the top element.
        """
        return self._que1[-1]
        

    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return not self._que1

### 解题思路
使用双向队列基本操作完成


class MyStack(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        from collections import deque
        self.q=deque()


    def push(self, x):
        """
        Push element x onto stack.
        :type x: int
        :rtype: None
        """
        self.q.appendleft(x)


    def pop(self):
        """
        Removes the element on top of the stack and returns that element.
        :rtype: int
        """
        return self.q.popleft()


    def top(self):
        """
        Get the top element.
        :rtype: int
        """
        return self.q[0]


    def empty(self):
        """
        Returns whether the stack is empty.
        :rtype: bool
        """
        if len(self.q)==0:
            return True
        else:
            return False

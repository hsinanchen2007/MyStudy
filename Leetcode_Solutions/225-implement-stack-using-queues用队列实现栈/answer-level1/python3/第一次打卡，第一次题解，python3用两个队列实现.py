### 解题思路
代码如下
class MyStack(object):      # 使用两个队列实现

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.data = []
        self.help = []


    def push(self, x):
        """
        Push element x onto stack.
        :type x: int
        :rtype: None
        """
        self.data.append(x)


    def pop(self):
        """
        Removes the element on top of the stack and returns that element.
        :rtype: int
        """
        while(len(self.data)>1):
            self.help.append(self.data.pop(0))
        tmp = self.data.pop(0)
        self.data, self.help = self.help, self.data     # 两个元素交换值，不用放置临时tmp
        return tmp


    def top(self):
        """
        Get the top element.
        :rtype: int
        """
        while(len(self.data)>1):
            self.help.append(self.data.pop(0))
        tmp = self.data.pop(0)
        self.data, self.help = self.help, self.data     # 两个元素交换值，不用放置临时tmp
        self.data.append(tmp)
        return tmp


    def empty(self):
        """
        Returns whether the stack is empty.
        :rtype: bool
        """
        return len(self.data)==0





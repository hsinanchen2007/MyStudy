```
class MinStack(object):

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.s1 = [] 
        self.s2 = []

    def push(self, x):
        """
        :type x: int
        :rtype: void
        """
        if not self.s2 or x <= self.getMin():
            self.s2.append(x) 
            
        self.s1.append(x)

    def pop(self):
        """
        :rtype: void
        """
        if self.s1[-1] == self.getMin():
            self.s2.pop()
            
        self.s1.pop()

    def top(self):
        """
        :rtype: int
        """
        return self.s1[-1]

    def getMin(self):
        """
        :rtype: int
        """
        return self.s2[-1]
```
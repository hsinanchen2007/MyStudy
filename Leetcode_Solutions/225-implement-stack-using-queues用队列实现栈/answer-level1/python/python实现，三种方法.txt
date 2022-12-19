### 解题思路
官方讲的已经很好了哈哈哈哈哈

#### 方法一，时间复杂度, pushO(1), popO(n)
```
class MyStack1(object):
    
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.q1 = []
        self.q2 = []


    def push(self, x):
        """
        Push element x onto stack.
        :type x: int
        :rtype: None
        """
        self.q1.append(x)


    def pop(self):
        """
        Removes the element on top of the stack and returns that element.
        :rtype: int
        """
        while len(self.q1) > 1:
            self.q2.append(self.q1.pop(0))
        res = self.q1.pop()
        self.q1, self.q2 = self.q2, self.q1
        return res


    def top(self):  # O1
        """
        Get the top element.
        :rtype: int
        """
        if len(self.q1) != 0:
            return self.q1[-1]
        else:
            return -1


    def empty(self):  # O1
        """
        Returns whether the stack is empty.
        :rtype: bool
        """
        return self.q1 == [] and self.q2 == []

```
##### 方法二，时间复杂度, pushO(n), popO(1)
```
class MyStack2(object):
    
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.q1 = []
        self.q2 = []


    def push(self, x):
        """
        Push element x onto stack.
        :type x: int
        :rtype: None
        """
        self.q2.insert(0, x)
        while len(self.q1) != 0:
            self.q2.insert(0, self.q1.pop())
        self.q1, self.q2 = self.q2, self.q1
        


    def pop(self):
        """
        Removes the element on top of the stack and returns that element.
        :rtype: int
        """
        return self.q1.pop() 


    def top(self):
        """
        Get the top element.
        :rtype: int
        """
        return self.q1[-1]


    def empty(self):
        """
        Returns whether the stack is empty.
        :rtype: bool
        """
        return self.q1 == []
```
##### 方法三，单队列实现，时间复杂度, pushO(n), popO(1)
```
class MyStack3(object):
    
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.q = []


    def push(self, x):
        """
        Push element x onto stack.
        :type x: int
        :rtype: None
        """
        self.q.insert(0, x)
        self.q.append(self.q.pop(0))


    def pop(self):
        """
        Removes the element on top of the stack and returns that element.
        :rtype: int
        """
        return self.q.pop()
        


    def top(self):
        """
        Get the top element.
        :rtype: int
        """
        return self.q[-1]

    def empty(self):
        """
        Returns whether the stack is empty.
        :rtype: bool
        """
        return self.q == []
```


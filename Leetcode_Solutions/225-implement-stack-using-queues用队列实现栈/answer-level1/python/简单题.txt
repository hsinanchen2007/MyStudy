### 解题思路
此处撰写解题思路
一：首先定义一个队q。
二：push(x)：
1.首先几率q的长度size
2.将x放到队列中，q.append(x)
3.循环size次：每次循环取q的第一个元素，放到队尾。即temp=q.pop(0) q.append(temp)。这样可以保证每次push进来的x都在q的队首
三.pop(x):
取出队首元素即可：q.pop(0)
四.top()和pop类似
五.判断q的长度是否为0即可

### 代码

```python
class MyStack(object):

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
        size = len(self.q)
        self.q.append(x)
        for i in range(size):
            top = self.q.pop(0)
            self.q.append(top)


    def pop(self):
        """
        Removes the element on top of the stack and returns that element.
        :rtype: int
        """
        res = self.q.pop(0)
        return res


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
        return len(self.q)==0



# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```
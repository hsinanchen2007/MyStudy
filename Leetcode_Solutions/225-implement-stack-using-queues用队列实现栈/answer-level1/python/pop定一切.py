### 解题思路
push和empty都很好解决，就用list的性质就可以了。top和pop有点难，因为题目不让用自带的pop。所以我先做了一个队列的pop函数，只能删list的第一项。top和pop用while循环调用队列的pop就能解决了。


### 代码

```python
class MyStack(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.items = []
    def popfront(self):
        #这是队列的pop函数
        a = self.items[0]
        del self.items[0]
        return a
        
    def push(self, x):
        """
        Push element x onto stack.
        :type x: int
        :rtype: None
        """
        self.items.append(x)

    def pop(self):
        """
        Removes the element on top of the stack and returns that element.
        :rtype: int
        """
        # print "before pop:", self.items
        listhelper = []
        ans = 0
        #while循环
        while len(self.items) != 1:
            listhelper.append(self.items[0])
            self.popfront()
        ans = self.items[0]
        self.items = listhelper
        # print "after pop:", self.items
        return ans

    def top(self):
        """
        Get the top element.
        :rtype: int
        """
        helper = []
        ans = 0
        # print self.items
        #while循环
        while len(self.items) != 1:
            helper.append(self.items[0])
            self.popfront()
        ans = self.items[0]
        #这是pop和top的唯一区别
        helper.append(ans)
        self.items = helper
        return ans
        
    def empty(self):
        """
        Returns whether the stack is empty.
        :rtype: bool
        """
        if len(self.items) == 0:
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
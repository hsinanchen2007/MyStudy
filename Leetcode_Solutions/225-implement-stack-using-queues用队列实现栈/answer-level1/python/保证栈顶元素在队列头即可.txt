### 解题思路
鉴于队列的特殊性，保证栈顶元素在队列头即可。这样读是常量时间，写的话是O(n)。

另一种思路是，让写是常量时间，读的时候将队列滚动O(n)，本题没有采用这种方法。

### 代码

```python
class MyStack(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.queue = [[], []]
        self.cur = 0

    def push(self, x):
        """
        Push element x onto stack.
        :type x: int
        :rtype: None
        """
        self.queue[self.cur].append(x)
        the_other = self.cur ^ 1
        while self.queue[the_other]:
            data = self.queue[the_other][0]
            self.queue[the_other] = self.queue[the_other][1:]
            self.queue[self.cur].append(data)
        self.cur ^= 1

    def pop(self):
        """
        Removes the element on top of the stack and returns that element.
        :rtype: int
        """
        data = self.queue[self.cur ^ 1][0]
        self.queue[self.cur ^ 1] = self.queue[self.cur ^ 1][1:]
        return data

    def top(self):
        """
        Get the top element.
        :rtype: int
        """
        return self.queue[self.cur ^ 1][0]

    def empty(self):
        """
        Returns whether the stack is empty.
        :rtype: bool
        """
        return not bool(self.queue[self.cur]) and not bool(self.queue[self.cur ^ 1])


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```
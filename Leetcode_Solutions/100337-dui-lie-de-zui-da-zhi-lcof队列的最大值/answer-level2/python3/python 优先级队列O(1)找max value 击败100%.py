### 解题思路
maxval为优先级队列，保证队列单调递减，加入元素时如果value大于队列尾部val就pop，保证队列单调性。（这题目也中等难度。。）

### 代码

```python
class MaxQueue(object):

    def __init__(self):
        self.li = []
        self.maxval = []

    def max_value(self):
        """
        :rtype: int
        """
        if not self.li:
            return -1
        return self.maxval[0]


    def push_back(self, value):
        """
        :type value: int
        :rtype: None
        """
        while self.maxval and value > self.maxval[-1]:
            self.maxval.pop()
        self.maxval.append(value)
        self.li.append(value)

    def pop_front(self):
        """
        :rtype: int
        """
        if not self.li:
            return -1
        if self.li[0] == self.maxval[0]:
            self.maxval.pop(0)
        return self.li.pop(0)



# Your MaxQueue object will be instantiated and called as such:
# obj = MaxQueue()
# param_1 = obj.max_value()
# obj.push_back(value)
# param_3 = obj.pop_front()
```
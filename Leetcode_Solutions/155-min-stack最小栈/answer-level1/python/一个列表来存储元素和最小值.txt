### 解题思路
关键在push新元素的时候，把目前已经在栈里的元素最小值也存进去，这样在pop后获取最小值不用遍历去求值了。

本来还做了很多空的判断，譬如空的时候pop，top等动作的时候异常处理，但是发现不需要，就清了。

PS：python的小伙伴不要用min等函数，会变慢

### 代码

```python
class MinStack(object):

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.min_value = 0
        self.l1 = []

    def push(self, x):
        """
        :type x: int
        :rtype: None
        """
        if len(self.l1) == 0:
            self.min_value = x
        elif x < self.min_value:
            self.min_value = x
        self.l1.append((x, self.min_value))


    def pop(self):
        """
        :rtype: None
        """
        if len(self.l1) != 0: del self.l1[-1]
        if len(self.l1) != 0: self.min_value = self.l1[-1][1]
        

    def top(self):
        """
        :rtype: int
        """
        return self.l1[-1][0]
        

    def getMin(self):
        """
        :rtype: int
        """
        return self.min_value
        


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
```
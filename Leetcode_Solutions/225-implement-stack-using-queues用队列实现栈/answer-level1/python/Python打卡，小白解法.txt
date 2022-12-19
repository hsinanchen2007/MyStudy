### 解题思路
前面对栈push的插入位置弄不清，多花了点时间
我没用自带的append()和pop(), 总结下我用到python的知识点：
初始化一定长度的列表
列表索引
列表深拷贝
简化的if else表达式
![image.png](https://pic.leetcode-cn.com/dc3e0a76a189532d045ddd5b5e589eee90496d1ce7115c2dfdcc1f4a535e6357-image.png)
结果上来时，用时比平均水平要少，内存消耗略少
### 代码

```python
class MyStack(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.stackA = []

    def push(self, x):
        """
        Push element x onto stack.
        :type x: int
        :rtype: None
        """
        n = len(self.stackA)
        stackB = [x]*(n+1)
        stackB[1:n+1] = self.stackA[:] 
        self.stackA = stackB[:]


    def pop(self):
        """
        Removes the element on top of the stack and returns that element.
        :rtype: int
        """
        m = self.stackA[0]
        self.stackA = self.stackA[1:]
        return m


    def top(self):
        """
        Get the top element.
        :rtype: int
        """
        return self.stackA[0]

    def empty(self):
        """
        Returns whether the stack is empty.
        :rtype: bool
        """
        return (True if self.stackA == [] else False)


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
```
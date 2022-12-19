### 解题思路
![image.png](https://pic.leetcode-cn.com/29d92b9cccb901ae110285f43b634fdd28c95b2779cbdc3ba0b1a51af7d368af-image.png)

- 使用一个辅助栈来保存现在栈中的最小元素,我们以`[-2,0,-3]`为例来看下,辅助栈为`min_`,原始栈为`stack`.
- **辅助栈中的最后一个元素为当前栈中的最小元素**,如果当前要进入的元素比最小元素小,那么将当前元素加入到`min_`中,否则在`min_`中加入`min[-1]`,也即最小元素
- --例子--
1. -2进栈,`stack=[-2]`,由于这是第一个元素,所以`min_=[-2]`直接入栈
2. 0入栈,`stack=[-2,0]`,这是就需要比较当前栈中的最小元素也就是`min_`中的最后一个元素-2和0的大小,-2<0,所以-2进入`min_`,`min_=[-2,-2]`
3. -3进栈,`stack=[-2,0,-3]`,这是就需要比较当前栈中的最小元素也就是`min_`中的最后一个元素-2和0的大小,-3<-2,所以-3进入`min_`,`min_=[-2,-2,-3]`
4. 当需要弹出的时候只需要将`min_`中的最后一个元素一起弹出即可

### 代码

```python
class MinStack(object):

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.min_ = []
        self.stack = []

    def push(self, x):
        """
        :type x: int
        :rtype: None
        """
        self.stack.append(x)
        if not self.min_ or x < self.min_[-1]:
            self.min_.append(x)
        else:
            self.min_.append(self.min_[-1])

    def pop(self):
        """
        :rtype: None
        """
        self.stack.pop()
        self.min_.pop()

    def top(self):
        """
        :rtype: int
        """
        if not self.stack:
            return None
        else:
            return self.stack[-1]

    def getMin(self):
        """
        :rtype: int
        """
        if not self.stack:
            return None
        else:
            return self.min_[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
```
### 解题思路
创建一个空数组，在循环中不断添加数字，最后移除0即可

### 代码

```python
class Solution(object):
    def printNumbers(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        self.a = []
        for i in range(10 ** n):#循环
            self.a.append(i)#添加数字   
        self.a.remove(0)#移除数字0
        return self.a
```
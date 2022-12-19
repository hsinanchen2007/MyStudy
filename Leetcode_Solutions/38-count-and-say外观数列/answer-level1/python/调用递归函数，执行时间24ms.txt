### 解题思路
写了一个读数函数，外加一个计数的函数。

### 代码

```python
class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        name = '1'
        for i in range(n-1):
            name = self.CountandSay(name)
        return name

    def CountandSay(self, str1):
        count = 1
        name = ''
        str1 = str1 + '0'
        for i in range(len(str1)-1):
            if str1[i] == str1[i+1]:
                count += 1
            else:
                name = name + str(count) + str1[i]
                count = 1
        return name
```
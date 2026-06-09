![image.png](https://pic.leetcode-cn.com/2120cce3a17a29a81a3f31f2a94a67c87be41ea2c4b0b2f4c76c3c82fb403eb5-image.png)

搞清楚常用函数的参数也是学习的目的之一，一共6行也很简洁。

```python []
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        i = 0
        for c in s:
            j = t.find(c, i)    #从第i位置开始查找
            if j == -1:         #find函数找不到值时会返回-1
                return False
            i = j + 1           #从当前点的下一个位置开始查找
        return True
```

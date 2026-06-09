### 解题思路
利用and机制，递归到参数n=0时，返回值为0，停止递归，运算终止。返回值为and右边的数值

### 代码

```python
class Solution(object):
    def sumNums(self, n):
        """
        :type n: int
        :rtype: int
        """
        return n and n+self.sumNums(n-1)
```
### 解题思路
执行用时 :20 ms, 在所有 Python 提交中击败了75.64%的用户
内存消耗 :11.7 MB, 在所有 Python 提交中击败了95.12%的用户

### 代码

```python
class Solution(object):
    def sumZero(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        b=list()
        if n%2!=0:
            b.append(0)
            for i in range(1,n//2+1):
                b.append(i)
                b.append(-i)
        if n%2==0:
            for i in range(1,n//2+1):
                b.append(i)
                b.append(-i)
        return b
```
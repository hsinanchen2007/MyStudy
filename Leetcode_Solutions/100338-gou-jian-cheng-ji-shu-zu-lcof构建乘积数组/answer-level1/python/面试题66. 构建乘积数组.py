### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def constructArr(self, a):
        """
        :type a: List[int]
        :rtype: List[int]
        """
        n = len(a)
        l, r = [1] * n, [1] * n
        for i in range(1,n):
            l[i] = l[i-1] * a[i-1]
        for i in range(n-2, -1, -1):
            r[i] = r[i+1] * a[i+1]
        for i in range(n):
            l[i] = l[i]*r[i]
        return l
```
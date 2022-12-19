### 解题思路
![截屏2020-03-0310.19.51.png](https://pic.leetcode-cn.com/a735706f1d5c9e1edd01476625763f24eeec573759179b43b8391a1a25fdd797-%E6%88%AA%E5%B1%8F2020-03-0310.19.51.png)
此处撰写解题思路

### 代码

```python
class Solution(object):
    def merge(self, A, m, B, n):
        """
        :type A: List[int]
        :type m: int
        :type B: List[int]
        :type n: int
        :rtype: None Do not return anything, modify A in-place instead.
        """
        for i in range(len(A)-1,m-1,-1):
            del A[i]
        A.extend(B)
        return A.sort()
```
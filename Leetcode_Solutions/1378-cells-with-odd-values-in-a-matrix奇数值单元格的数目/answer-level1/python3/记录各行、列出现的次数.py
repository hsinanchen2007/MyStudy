### 解题思路

记录各行、列出现的次数，偶数次相当于没操作，奇数次相当于操作了一次，最后再去掉各行列相交元素
### 代码

```python
class Solution(object):
    def oddCells(self, n, m, indices):
        """
        :type n: int
        :type m: int
        :type indices: List[List[int]]
        :rtype: int
        """
        h=[0]*n
        l=[0]*m
        for i in indices:
            h[i[0]]+=1
            l[i[1]]+=1
        h=[i for i in h if i%2!=0]
        l = [i for i in l if i % 2 != 0]

        return len(h)*m+len(l)*n-len(h)*len(l)*2

```
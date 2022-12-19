### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def maxProduct(self, nums):
        maxx=-100
        imin=1
        imax=1
        for i in nums:
            if i <0:
                temp=imax
                imax=imin
                imin=temp
            imax=max(i*imax,i)
            imin=min(i*imin,i)
            maxx=max(imax,maxx)
        return maxx
```
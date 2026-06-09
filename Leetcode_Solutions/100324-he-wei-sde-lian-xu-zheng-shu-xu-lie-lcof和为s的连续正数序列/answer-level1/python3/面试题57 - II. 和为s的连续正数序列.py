### 解题思路
因为是连续序列，所以可以用一个滑动窗口来完成。

### 代码

```python3
class Solution(object):
    def findContinuousSequence(self, target):
        """
        :type target: int
        :rtype: List[List[int]]
        """
        res=[]
        l=1
        r=2
        while l<r:
            a=[]
            sum=(l+r)*(r-l+1)/2
            if sum<target:
                r+=1
            elif sum>target:
                l+=1
            else:
                for i in range(l,r+1):
                    a.append(i)
                res.append(a)
                l+=1
                r+=1
        return res
```
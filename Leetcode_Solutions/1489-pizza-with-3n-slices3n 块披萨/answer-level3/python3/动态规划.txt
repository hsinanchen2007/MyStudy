# 思路

转化为从长度为3n的序列中提取长度为n的不相邻子序列问题。 注意首尾不相邻，可以通过算两遍解决。
时间复杂度 $O(n^2)$
空间复杂度 $O(N^2)$
#代码

```python []
class Solution:
    def maxSizeSlices(self, slices):
        import numpy as np
        def f(s,r):
            result=np.zeros((len(s)+2,r+1,2))
            result[0][1][1]=s[0]
            for i in range(1,len(s)):
                for j in range(1,min(r+1,i+1)):
                    result[i][j][0]=max(result[i-1][j][0],result[i-1][j][1])
                    result[i][j][1]=result[i-1][j-1][0]+s[i]

            return np.max(result)
        return int(max(f(slices[:-1],len(slices)//3),f(slices[1:],len(slices)//3)))

```


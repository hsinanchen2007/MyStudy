@[TOC](303. 区域和检索 - 数组不可变（Range Sum Query - Immutable）)
# 题解
每次调用函数计算一次都需要$O(n)$复杂度，因此借助缓存来保存区域和。
若使用二维$dp$，$dp[i][j]$表示$i$到$j$的区域和，需要$O(n^{2})$空间复杂度。
考虑以上因素，我们使用一维$dp$，其中$dp[i]$表示到$i-1$索引处的累加和。则易得$i$到$j$的区域和公式：
$dp[j+1]-dp[i]$
## 缓存+动态规划
 1. 特判，若数组为空，返回。
 2. 初始化$dp=[0,\cdots,0]$，长度为$n+1$。
 3. 遍历数组，保存累加和，遍历区间$[2,n+1)$：
 	+ dp[i]=nums[i-1]+dp[i-1]
 4. 索引$i$到$j$间的区域和公式：$dp[j+1]-dp[i]$

	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
### 复杂度分析
 - 时间复杂度：$O(n)$，每次查询只需要$O(1)$
 - 空间复杂度：$O(n)$

### Python
```python
class NumArray:

    def __init__(self, nums: List[int]):
        if(not nums):
            return 
        n=len(nums)
        self.dp=[0]*(n+1)
        self.dp[1]=nums[0]
        for i in range(2,n+1):
            self.dp[i]=nums[i-1]+self.dp[i-1]

    def sumRange(self, i: int, j: int) -> int:
        return self.dp[j+1]-self.dp[i]
```


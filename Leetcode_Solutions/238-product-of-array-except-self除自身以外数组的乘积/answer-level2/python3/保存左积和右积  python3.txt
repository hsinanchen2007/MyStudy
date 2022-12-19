# 题解
使用左边乘积和右边乘积进行计算。
## 左积和右积
 1. 初始化数组长度$n$。初始化$res=[0,0,...,0]$为$1*n$的数组。初试化乘积$k=1$
 2. 从左向右遍历，遍历区间$[0,n)$：
 	+ $res$每个位置保存它左侧所有元素的乘积。即$res[i]=k,k*=nums[i]$
 
 3. 重置乘积$k=1$，用来保存元素右边的乘积和
 4. 从右向左遍历，遍历区间$(n,0]$：
 	+ $res[i]*=k$，表示将当前位置的左积乘以右积。
 	+ 更新右积$k*=nums[i]$
 6. 返回$res$

### 复杂度分析
 - 时间复杂度：$O\left(n\right)$，进行了两次次遍历。
 - 空间复杂度：$O(n)$，借助$res$保存结果

### Python

```python
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n=len(nums)
        res=[0]*n
        k=1
        for i in range(n):
            res[i]=k
            k=k*nums[i]
        k=1
        for i in range(n-1,-1,-1):
            res[i]*=k
            k*=nums[i]
        return res
```

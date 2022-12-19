## 排序+双指针
### 算法流程：

 1. 特判，对于数组长度$n$，如果数组为Null或者数组长度小于3，返回$[]$。
 2. 对数组进行排序，并定义$res$，保存最接近和。
 3. 遍历排序后数组：
    - 对于重复元素，跳过，避免重复计算（也可以不跳过）
    - 令左指针$L=i+1$,右指针$R=n-1$,当$L<R$时，执行循环：
      *令$cur\_sum=nums[i]+nums[L]+nums[R]$,如果$cur\_sum=target$,返回$target$
      *若$abs(cur\_sum-target)<abs(res-target)$,说明$cur\_sum$更接近目标，更新$res$
      *若$cur\_sum-target$大于0，说明$nums[R]$太大，$R$左移
      *若$cur\_sum-target$小于0，说明$nums[L]$太小，$L$右移
### 复杂度分析

 - 时间复杂度：$O\left(n^{2}\right)$，数组排序$O(N \log N)$，遍历数组$O\left(n\right)$，双指针遍历$O\left(n\right)$，总体$O(N \log N)+O\left(n\right)*O\left(n\right)$，$O\left(n^{2}\right)$
 - 空间复杂度：$O(1)$

### Python

```python
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        n=len(nums)
        if(not nums or n<3):
            return None
        nums.sort()
        res=float("inf")
        for i in range(n):
            if(i>0 and nums[i]==nums[i-1]):
                continue
            L=i+1
            R=n-1
            while(L<R):
                cur_sum=nums[i]+nums[L]+nums[R]
                
                if(cur_sum==target):
                    return target
                if(abs(cur_sum-target)<abs(res-target)):
                    res=cur_sum
                if(cur_sum-target<0):
                    L+=1
                else:
                    R-=1
        return res
## 排序+双指针
**和三数之和一样，本题的难点依旧在于如何去除重复解**
**取两个数组合，将问题转化为三数之和**
### 算法流程：

 - 特判，对于数组长度$n$，如果数组为Null或者数组长度小于4，返回$[]$。
 - 对数组进行排序。
 - 遍历排序后数组：
    - 对于重复元素，跳过，条件：$i>0 且 nums[i]==nums[i-1]$，避免出现重复解
    - 二次遍历，重复元素跳过，判断重复元素从$i$后第二个元素开始，所以条件：$j-i>1 且 nums[j]==nums[j-1]$ 
    - 令左指针$L=j+1$,右指针$R=n-1$,当$L<R$时，执行循环：
      *当$nums[i]+nums[j]+nums[L]+nums[R]==target$时,将结果加入$res$并执行循环，判断左界和右界是否和下一位置重复，以去除重复解。并同时将$L,R$移到下一位置，寻找新的解
      *若和大于0，说明$nums[R]$太大，$R$左移
      *若和小于0，说明$nums[L]$太小，$L$右移
### 剪枝条件：
对于本题，按照上述流程写下来，可以通过。
我们继续对算法进行剪枝优化
 **第一次遍历**
 
 - 若$nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target$,则可以退出，因为最小四数之和大于目标，则不可能存在结果。**注意：**和三数之和的优化条件不同，三数之和中$target=0$,所以只要$nums[i]>0$,则可退出，这里则需要更为严格的条件。  
 - 若当前值和数组中最大的三个值相加依旧小于目标，$nums[i] + nums[n- 1] + nums[n- 2] + nums[n-
   3] < target$,则continue

  
**第二次遍历**

 - 同理，若$nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target$,break
 - $nums[i] + nums[j] + nums[n - 1] + nums[n - 2] < target$,continue

### 复杂度分析

 - 时间复杂度：$O\left(n^{3}\right)$，数组排序$O(N \log N)$，两次遍历数组$O\left(n^{2}\right)$，双指针遍历$O\left(n\right)$，总体$O(N \log N)+O\left(n^{2}\right)*O\left(n\right)$，$O\left(n^{3}\right)$
 - 空间复杂度：$O(1)$

### Python

```python
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        n=len(nums)
        if(not nums or n<4):
            return []
        nums.sort()
        res=[]
        for i in range(n-3):
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target):
                break
            if(nums[i]+nums[-1]+nums[-2]+nums[-3]<target):
                continue
            if(i>0 and nums[i]==nums[i-1]):
                continue
            for j in range(i+1,n-2):
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target):
                    break
                if(nums[i]+nums[j]+nums[-1]+nums[-2]<target):
                    continue
                if(j-i>1 and nums[j]==nums[j-1]):
                    continue
                L=j+1
                R=n-1
                while(L<R):
                    if(nums[i]+nums[j]+nums[L]+nums[R]==target):
                        res.append([nums[i],nums[j],nums[L],nums[R]])
                        while(L<R and nums[L]==nums[L+1]):
                            L=L+1
                        while(L<R and nums[R]==nums[R-1]):
                            R=R-1
                        L=L+1
                        R=R-1
                    elif(nums[i]+nums[j]+nums[L]+nums[R]>target):
                        R=R-1
                    else:
                        L=L+1
        return res
```
**优化后，有明显提升**![在这里插入图片描述](https://pic.leetcode-cn.com/453ca537658cab1e3ba58d12eb1bbc3214d7c1a408de7a1f960e42c65b61e306.png)

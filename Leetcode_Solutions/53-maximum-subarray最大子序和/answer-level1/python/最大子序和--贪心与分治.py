### 贪心
O(N),遍历一次序列，只记录可以组成的子序列最大和
输出res
if 判断
1）子序和最大时，对res更新
2）子序和小于0时，到i的前段子序丢弃
3）子序和比状态结果res小，但是和大于0，暂时保存该子序和
4）子序和小于状态结果，且和为负，舍弃前段子序，初始化成0
5）end for；return res

```
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        if not nums:
            return 0
        if max(nums) < 0:
            return max(nums)
        Len = len(nums)
        res = 0
        temp = 0        
        for i in range(Len):
            temp += nums[i]
            if temp >= res and temp >= 0:
                res = temp
            elif temp >= res and temp <0:
                temp = 0
                res = max(temp,res)
            elif temp <= res and temp >= 0:
                res = max(temp,res)
            else:
                temp = 0
                res = max(res, temp)
                
        return res
```

### 分治
根据中心位置，进行分块处理
分块儿后，进行递归计算两侧得到max_left，max_right
如果是跨中心的子序，则只需要分别计算近邻的左右最大子序max_l和max_r，然后相加
return max(max_left, max_right, max_l+max_r)

```
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        n = len(nums)
        if n<=1:
            return max(nums)
        else:
            max_left = self.maxSubArray(nums[0:n//2])
            max_right = self.maxSubArray(nums[n//2:n])
        max_l = nums[n//2-1]
        temp = 0
        for i in range(n//2-1,-1,-1):
            #查找跨中心位置的左侧子序，倒序遍历，间隔1
            temp += nums[i]
            max_l = max(temp, max_l)
        max_r = 0
        temp = 0
        for i in range(n//2,n):
            #查找跨中心的右侧子序
            temp += nums[i]
            max_r = max(temp, max_r)
        return max(max_left, max_right, max_l+max_r)
```
备注：*分治提交的结果耗时总是在200ms+，而贪心大概在80ms左右*
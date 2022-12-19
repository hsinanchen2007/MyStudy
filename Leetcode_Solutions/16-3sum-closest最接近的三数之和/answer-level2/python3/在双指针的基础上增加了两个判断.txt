### 解题思路

### 代码

```python3
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        #nums长度
        if len(nums)<3:
            return False
        if len(nums)==3:
            return nums[0]+nums[1]+nums[2]
        
        #自小向大排序
        nums.sort()
        #初始化前三个数的和作为当前的target的最接近值
        cloest = nums[0]+nums[1]+nums[2]
        
        #双指针
        for i in range(len(nums)-2):
            left = i+1
            right = len(nums)-1
            
            #判断1：最小的比target大
            if nums[i]+nums[i+1]+nums[i+2]>target:
                if abs(target-(nums[i]+nums[i+1]+nums[i+2])) < abs(target -cloest):
                    cloest = nums[i]+nums[i+1]+nums[i+2]
                break
            
            
            #判断2：最大的比target小
            if nums[i]+nums[-2]+nums[-1]<target:
                if abs(target-(nums[i]+nums[-2]+nums[-1])) < abs(target -cloest):
                    cloest = nums[i]+nums[-2]+nums[-1]
                continue
            
            
            while left<right:
            
                now = nums[i]+nums[left]+nums[right]
                #判断当前是否更接近
                if abs(target-now) < abs(target -cloest):
                    cloest = now
                    
                if now>target:
                    right -= 1
                elif now==target:
                    return target
                elif now<target:
                    left += 1
            
        return cloest
```
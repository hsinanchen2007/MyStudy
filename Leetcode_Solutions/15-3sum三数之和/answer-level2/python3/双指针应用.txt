### 解题思路
双指针的又一经典题型，每次遍历列表中的元素，寻求两个数的和为-nums[i]，因此就可以采用双指针来遍历剩余的元素，还可以优化，例如若nums[i]>=0时直接跳出循环等等方式

### 代码

```python3
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        if len(nums)<3:
            return []
        nums.sort()
        final_result=[]
        first_set=set()
        for i in range(len(nums)-2):
            if nums[i] in first_set:
                continue
            if nums[i]>=0:
                break
            left = i+1
            right=len(nums)-1
            target = -nums[i]
            left_set = set()
            while(left<right):
                sum_lr = nums[left]+nums[right]
                if(sum_lr>target):
                    right-=1
                elif(sum_lr<target):
                    left+=1
                elif(sum_lr==target):
                    if(nums[left] in left_set):
                        left+=1
                        continue
                    if(nums[right] in left_set):
                        right-=1
                        continue
                    final_result.append([nums[i],nums[left],nums[right]])
                    left_set.add(nums[left])
                    left_set.add(nums[right])
            first_set.add(nums[i])
        return final_result

```
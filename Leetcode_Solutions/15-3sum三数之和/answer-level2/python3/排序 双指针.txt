### 解题思路
1.当数组为空或数组长度<3时，返回[]
2.排序数组，遍历数组元素，若当前元素值>0，则之后不可能有=0的和，返回当前结果数组
3.若元素重复，为避免产生重复结果，跳过重复数字：注意要跳过重复的i、l、r
4.当和为0时，将当前结果加入结果数组中
5.当和<0时，l+1;当和>0时，r-1

### 代码

```python3
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        sum_zero = []
        nums.sort()
        if not nums or n<3:
            return []
        for i in range(n-2):
            if nums[i]>0:
                return sum_zero
            else:
                if i>0 and nums[i]==nums[i-1]:
                    continue
                l = i+1
                r = n-1
                while l<r:
                    if nums[i]+nums[l]+nums[r]==0:
                        sum_zero.append([nums[i], nums[l], nums[r]])
                        while l<r and nums[l]==nums[l+1]:
                            l += 1
                        while l<r and nums[r]==nums[r-1]:
                            r -= 1
                        l += 1
                        r -= 1
                    elif nums[i]+nums[l]+nums[r]>0:
                        r -= 1
                    else:
                        l += 1
        return sum_zero
        
```
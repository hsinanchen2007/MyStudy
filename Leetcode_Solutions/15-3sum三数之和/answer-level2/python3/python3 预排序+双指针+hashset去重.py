### 解题思路
先取第一个数nums[i]，使用双指针法在剩余数组中取nums[j]和nums[k]，使得nums[j]+nums[k]=-nums[i]。
时间复杂度：O(n^2)

### 代码

```python3
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res=set()
        nums.sort()
        for i in range(len(nums)-2):
            if nums[i]>0:
                break
            if i>0 and nums[i]==nums[i-1]:
                continue
            target=-nums[i]
            j=i+1
            k=len(nums)-1
            while j<k:
                if nums[j]+nums[k]==target:
                    res.add((nums[i],nums[j],nums[k]))
                    j+=1
                    k-=1
                elif nums[j]+nums[k]<target:
                    j+=1
                else:
                    k-=1
        return list(res)
```
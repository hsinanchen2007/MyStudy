- 注意一些特殊情况
- 0 0 2 2 5这种存在重复的 肯定组不成顺子
- 0 0 2 3 8这种最大最小值之差大于4的肯定组不成
- 0 0 2 6 7这种a[i] 间隙过大的也不可以 间隙应该用 同等数目的0补齐 而不是只填补一个
```
class Solution:
    def isStraight(self, nums: List[int]) -> bool:
        nums.sort()
        if nums[0]!=0:
            for i in range(1,5):
                if nums[i] != nums[i-1]+1:
                    return False
            return True
        else:
            count = 2 if nums[1] == 0 else 1
            
            for i in range(2,5):
                if nums[i-1]==0: continue
                if nums[i]==0: continue
                if nums[i]==nums[i-1] and nums[i] != 0: return False
                if nums[-1]-nums[i] > 4: return False 
                if nums[i] != nums[i-1]+1:
                    if count <(nums[i]-nums[i-1]-1):
                        return False
                    count -= (nums[i]-nums[i-1]-1)
            return True

```

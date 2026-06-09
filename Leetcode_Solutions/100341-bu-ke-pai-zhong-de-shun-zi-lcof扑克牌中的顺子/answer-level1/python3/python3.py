1.判断0的个数
2.nums去0排序
3.nums内有重复元素则False
4.nums首尾元素差值应在[4-c,4]之间

```
class Solution:
    def isStraight(self, nums: List[int]) -> bool:
        nums = sorted(nums)
        c = 0
        for i in nums:
            if i == 0:
                c += 1
            else:
                break
        nums = nums[c:]
        if len(nums) != len(set(nums)):
            return False
        a = nums[-1] - nums[0]
        if a <= 4 and a >= 4-c:
            return True
        return False
```



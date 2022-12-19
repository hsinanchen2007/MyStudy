```
class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if nums == []:
            return 0
        bad_val = nums[-1] + 1
        i = 0
        #把超过2次出现的值从第三个开始都赋值成一个bad_val
        while i < len(nums) - 2:
            num_count = nums.count(nums[i])
            if nums[i] != bad_val and num_count > 2:
                nums[i+2:i+num_count] = [bad_val for j in range(num_count-2)]
                i += num_count-2
            else:
                i += 1
        nums.sort()
        return len(nums)-nums.count(bad_val)
```

#每计算一次count就需要遍历一次，所以性能比较差
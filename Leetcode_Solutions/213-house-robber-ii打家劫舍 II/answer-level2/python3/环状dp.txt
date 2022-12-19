这个问题分情况即可，对于第一个是否被偷分两种情况，其余就是简单dp,通常处理环状问题可以在数组后接一个同样的数组或者对环状数组的第一个值分类讨论
```
class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        num_one = nums[1:]
        num_two = nums[2:-1]
        dp_one = [0 for _ in range(len(num_one))]
        dp_two = [0 for _ in range(len(num_two))]

        for i in range(len(num_one)):
            if i>0:
                dp_one[i] = max(dp_one[i-1],dp_one[i-2] + num_one[i])
            else:
                dp_one[i] = num_one[i]
        for i in range(len(num_two)):
            if i>0:
                dp_two[i] = max(dp_two[i-1],dp_two[i-2] + num_two[i])
            else:
                dp_two[i] = num_two[i]
        
        if len(dp_one) == 0:
            dp_one = [0]
        if len(dp_two) == 0:
            dp_two = [0]
        return max(dp_one[-1],dp_two[-1] + nums[0])
```

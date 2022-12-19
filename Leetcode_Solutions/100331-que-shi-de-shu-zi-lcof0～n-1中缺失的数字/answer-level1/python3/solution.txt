### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def missingNumber(self, nums):
        if len(nums) == 1:
            if nums[0] > 0:
                return nums[0] - 1
            return nums[0] + 1
        for i in range(1, len(nums)):
            if nums[i] - nums[i-1] != 1:
                return nums[i] - 1
        else:
            if nums[0] != 0:
                return nums[0] - 1
            return nums[i] + 1
```这个题目我的理解是，要有一个0-n-1之间的数，
1 如果只有一个数，而且大于0的话，那么它的相邻的数就是0，如果这个数等于0，那么毫无疑问相邻数是1，这是只有一个数的情况
2 在多个数的情况下，如果是例如[1,2,3]这样的，那么他们的相邻数就是0，这是根据它的范围确定的，如果是形如[1, 3, 4]这样的数，很明显它的相邻就是2
### 解题思路
1. range(len(List))
2. 两次循环会超出时间限制
3. 关键在于看 target - num1是否也在list中
4. 确保不是同样index的两个数相加，所以break的条件有两个
5. List中某一数的index的输出方法：List.index(value)

### 代码

```python3
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(len(nums)):
            num1 = nums[i]
            num2 = target - num1
            if (num2 in nums) and (nums.index(num2) != i):
                j = nums.index(num2)
                break
        return [i,j]


```
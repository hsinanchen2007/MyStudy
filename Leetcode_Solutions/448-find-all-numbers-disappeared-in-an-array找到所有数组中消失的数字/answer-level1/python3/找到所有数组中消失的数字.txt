### 解题思路
难点在于时间复杂度上，第28个测试用例总是超时。
思路：采用“一个萝卜一个坑”的想法，把nums里出现的值，当成是新数组的下标，对应下标的值记为1；反查值不为1的位置的下标，就是缺失的值。

### 代码

```python3
class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        if len(nums) <= 1:
            return nums
        notIn = [0] * len(nums)
        for num in nums:
            notIn[num-1] = 1

        for i in range(len(nums)):
            if notIn[i] == 0:
                notIn.append(i+1)
        return notIn[len(nums):]



      
```
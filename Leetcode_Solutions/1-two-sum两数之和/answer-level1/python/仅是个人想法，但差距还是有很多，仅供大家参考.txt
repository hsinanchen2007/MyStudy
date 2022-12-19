### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        for i in range(len(nums)):
            for j in range(len(nums)):
                if nums[i] + nums[j] == target:
                    if i == j:
                        continue
                    else:
                        return [i, j]
                else:
                    continue
想来真是惭愧，一开始用python3运行报超出时间限制，无奈只能用python去跑，还好通过了，但和其他人比起来内存消耗和时间复杂度太高，以前的我从未考虑时间复杂度这个东西，只考虑能否运行出来，因为本科学的不是计算机，python只是自学，还要继续加油努力！
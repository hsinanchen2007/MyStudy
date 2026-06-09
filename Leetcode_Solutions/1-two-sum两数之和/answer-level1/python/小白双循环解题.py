### 解题思路
没学过算法和数据结构之类的课程，就用了我能想到的最直接的方法
用两个FOR循环来分别遍历数组

*第一次解题时还写了一个i不等于j的判断，结果后来参考了一些别人的题解，发现没有这个必要*

### 代码

```python3
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(0,len(nums)):
            for j in range(i+1,len(nums)):
                    if nums[i]+nums[j] == target:
                        return [i,j]

```
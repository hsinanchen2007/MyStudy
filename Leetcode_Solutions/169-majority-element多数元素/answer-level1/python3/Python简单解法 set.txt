### 解题思路
1、首先题目说的很清楚：一定存在多数，同时只有一个多数，而且非空，这就降低了难度
2、先给nums去重，
3、然后再统计每个值在nums中的个数，就直接得到答案了

### 代码
```
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        a = set(nums)
        b  = len(nums)/2
        for i in a:
            if nums.count(i)>b:
                return i
```

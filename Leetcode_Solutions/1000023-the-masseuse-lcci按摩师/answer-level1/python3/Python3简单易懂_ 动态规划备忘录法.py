这题目描述真是要开车的节奏...

### 解题思路
这题明显是动态规划的题目.
先用递归写出数学归纳式, 即M(i) = max(M(i - 2) + nums[i], M(i - 1)), 含义大概就是是否选取i这个顾客.
然后可以看出计算中会有很多重叠计算, 那么我用备忘录法加入一个字典记录中间计算结果来解决.

### 代码

```python3
class Solution:
    def massage(self, nums: List[int]) -> int:
        d = {}
        def max_minute(nums, index):
            if index < 0:
                return 0
            if index == 0:
                return nums[0]
            if index in d:  # 先查一下字典有没有
                return d[index]
            res = max(nums[index] + max_minute(nums, index - 2),  max_minute(nums, index - 1))
            d[index] = res  # 返回结果前先存一次字典
            return res
        
        return max_minute(nums, len(nums) - 1)

        
```
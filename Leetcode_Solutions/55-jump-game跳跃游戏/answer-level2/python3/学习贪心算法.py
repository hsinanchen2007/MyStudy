### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        #贪心算法，每一步考虑最远，如果能到达的最远位置大于最后一个位置，自然能到达最后一位
        max_i = 0   #初始化最远位置0
        for i ,jump in enumerate(nums):    #取i为索引，jump为nums[i]
            if max_i >= i and i+jump >max_i:#当前位置小于能到达的最远位置，且在最大跳下能大于最远位置
                max_i = i+jump              #则更新最远位置
        return max_i >=i                     #最后判断能到达的最远位置是否大于数组长度
            
```
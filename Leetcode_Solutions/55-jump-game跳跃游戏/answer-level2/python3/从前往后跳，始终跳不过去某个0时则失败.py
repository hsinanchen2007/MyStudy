思路：不能到达终点，必定是数组中含有数字0；而且某个0之前的位置，无论怎么跳，都必然会落在该0位置处。（联想上一跳跃游戏的题目——贪心算法）
1. 无论怎么跳，都跳不过去某个位置处的0，假设该0位置索引为index；
2. 遍历该0之前的每个位置i，以其最大能力跳跃所能达到的位置为i+nums[i]，均小于等于index；
3. 用max_p存储遍历过程中，所能达到的最远位置索引；
4. 当遍历到index处的0位置时，max_p 恰好也等于 index 时，则说明跳不过去了。

```
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        l = len(nums)
        
        if l == 0:return False
        max_p = 0
        
        for i in range(l-1):
            max_p = max(max_p, i+nums[i])
            if max_p == i and nums[i] == 0:return False
        
        return True
```


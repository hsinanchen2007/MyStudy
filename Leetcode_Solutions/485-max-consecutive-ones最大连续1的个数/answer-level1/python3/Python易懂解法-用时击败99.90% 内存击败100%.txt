![螢幕快照 2019-12-16 上午12.46.59.png](https://pic.leetcode-cn.com/66350fa69a8e3720905a6ff5b0962ec2e07bf775d79ab5afd6427b889528e4fe-%E8%9E%A2%E5%B9%95%E5%BF%AB%E7%85%A7%202019-12-16%20%E4%B8%8A%E5%8D%8812.46.59.png)
### 解题思路
使用一个变量当作我们要返回的变量来记录最大长度  
再使用一个变量作为记录1线段开始的指针，若遇到0代表需要判断一下从init_idx到0之间的线段有没有要更新最大长度
之后再继续判断

要另外注意的是若结尾为1的情况，需要主动截断最后一段1的数组再判断是否需要更新最大长度即可

### 代码

```python3
class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        max_length = 0
        init_idx = 0
        if len(nums) < 1:
            return 0
        for num_idx in range(len(nums)):
            if nums[num_idx] == 0:
                max_length = max(max_length,num_idx-init_idx)
                init_idx = num_idx+1
        if nums[-1] == 1:
            max_length = max(max_length, len(nums)-init_idx)
        return max_length
```
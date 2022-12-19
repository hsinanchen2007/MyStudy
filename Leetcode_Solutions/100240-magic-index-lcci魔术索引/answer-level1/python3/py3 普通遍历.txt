### 解题思路
100题啦~~纪念一下
内存击败100%
时间不咋地 击败57.95%
继续努力吧
### 代码

```python3
class Solution:
    def findMagicIndex(self, nums: List[int]) -> int:
        for i in range(0,len(nums)):
            if nums[i]==i:
                return i
        return -1
```
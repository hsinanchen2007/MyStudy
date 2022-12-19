### 解题思路
时空都是O(n)
排序+判断，方法不优秀，但是迅速
没想到竟然还有80+的时间排名
优化：
1、分治等等更快的排序方法
2、在排序过程中，其实可以定位正数，时空复杂度都可以降低

### 代码

```python3
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        nums.sort()
        posiInt=1
        for i in nums:
            if i<posiInt:
                continue
            elif i==posiInt:
                posiInt+=1
            else:
                return posiInt
        return posiInt
```
### 解题思路
看最大最小值之差是不是小于5，如果小于5，这五个数除了0之外又没得重复，肯定时顺子咯
注意：很明显0不能是最小值，且选的牌不能有重复。

### 代码

```python3
class Solution:
    def isStraight(self, nums: List[int]) -> bool:
        nums_map=set()
        min_nums=float("inf")
        max_nums=-1
        for i in nums:
            if i!=0:
                min_nums=min(min_nums,i)
                max_nums=max(max_nums,i)
            if i in nums_map and i!=0:
                return False
            nums_map.add(i)
        return max_nums-min_nums<5
        
        
```
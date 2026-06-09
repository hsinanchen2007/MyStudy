### 解题思路
此处撰写解题思路
1：首先对列表进行排序（从小到大）。
2：len（nums）得出列表的长度；将列表的长度与k值进行比较；列表长度小于k，不存在第k小的数；列表长度大于等于k值得时候，说明列表中存在第k小的值，由于列表已经排序，直接返回nums[-k]即为第k小的数。
### 代码

```python3
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        nums.sort()
        for num in nums:
            if len(nums)<k:
                return None
            elif len(nums)>=k:
                return nums[-k]
                
            
```
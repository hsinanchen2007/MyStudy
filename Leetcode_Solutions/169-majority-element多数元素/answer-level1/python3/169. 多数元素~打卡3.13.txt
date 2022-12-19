### 解题思路
考察python字典的基本操作和字典的排序
### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        from collections import defaultdict
        cnt = defaultdict(int)
        
        for num in nums:
            cnt[num] = cnt.get(num, 0) + 1
        
        cnt = sorted(cnt.items(), key=lambda x:-x[1])
        
        return cnt[0][0]
```
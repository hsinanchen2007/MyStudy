

### 代码

```python3
class Solution:
    def massage(self, nums: List[int]) -> int:


        last,now=0,0
        for num in nums:
            last,now=now,max(last+num,now)
        return now

```
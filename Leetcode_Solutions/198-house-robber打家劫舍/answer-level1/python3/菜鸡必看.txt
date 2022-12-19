### 解题思路
自己犯过的错误就是把last赋值为min(last+num,now)
其实直接就该是上一轮的now

### 代码

```python3
class Solution:
    def rob(self, nums: List[int]) -> int:
        last=now=0
        for num in nums:
            last,now=now,max(last+num,now)
        return now
```


### 代码

```python3
class Solution:
    def movesToMakeZigzag(self, nums: List[int]) -> int:
        e_count=o_count=0
        for i in range(len(nums)):
            ld=0 if i==0 else -rd+2
            rd=0 if i==len(nums)-1 else nums[i]-nums[i+1]+1
            add=max(0,ld,rd)
            if i%2==0:o_count+=add
            else: e_count+=add
        return min(e_count,o_count)
```
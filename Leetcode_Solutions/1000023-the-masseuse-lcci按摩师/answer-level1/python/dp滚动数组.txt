### 解题思路
#i=1
f(i)=nums[1]
#i=2
f(2)=max(nums[1],num[2])
#i>2
f(i)=max(f(i-1),f(i-2)+item)
### 代码

```python3
class Solution:
    def massage(self, nums: List[int]) -> int:
        last,now=0,0
        for item in nums:
            last,now=now,max(last+item,now)
        return now
```
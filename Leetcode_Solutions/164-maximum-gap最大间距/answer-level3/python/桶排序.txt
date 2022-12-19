### 解题思路
没啥特别讲的，关键在设置桶数量的时候把桶的数量设置成数组的长度。保证n个数落在n个桶里的时候，如果有2个数落在同一个桶内，那一定有一个空桶，从而保证桶内距一定小于桶间距。

### 代码

```python3
class Solution:
    def maximumGap(self, nums: List[int]) -> int:
        if len(nums)<=1:
            return 0
        max_,min_ = max(nums),min(nums)
        if max_==min_:
            return 0
        buckets = [[float("inf"),-float("inf")] for i in range(len(nums))]
        gap = (max_-min_)//len(nums)+1
        for n in nums:
            buckets[(n-min_)//gap][0] =min(buckets[(n-min_)//gap][0],n)
            buckets[(n-min_)//gap][1] =max(buckets[(n-min_)//gap][1],n)
        res = 0
        prev = float("inf")
        for x,y in buckets:
            if y == -float("inf"):
                continue
            res = max(res,x-prev)
            prev = y
        return res
        
            
```
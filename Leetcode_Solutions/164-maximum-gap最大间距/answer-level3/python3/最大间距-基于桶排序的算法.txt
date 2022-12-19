### 解题思路
![image.png](https://pic.leetcode-cn.com/aa1e8611c024f9acff87462844bdc2209dfd7dd1d896329d16ba1a179ab86294-image.png)

### 代码

```python3
import math

class Solution:
    def maximumGap(self, nums) -> int:
        if len(nums) < 2:
            return 0
        max_num, min_num = max(nums), min(nums)
        cap = math.ceil((max_num-min_num)/(len(nums)-1))
        if cap == 0:
            return 0
        k = (max_num-min_num)//cap+1
        bucket = [[] for i in range(k)]
        for i in range(len(nums)):
            bucket[(nums[i]-min_num)//cap].append(nums[i])
        res = []
        i = 0
        while i < k-1:
            if bucket[i+1] == []:
                j = i+1
                while not bucket[j]:
                    j += 1
                res.append(min(bucket[j])-max(bucket[i]))
                i = j
            else:
                res.append(min(bucket[i+1])-max(bucket[i]))
                i += 1
        return max(res)
```
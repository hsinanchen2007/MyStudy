### 解题思路
把python写成c

### 代码

```python3
class Solution:
    def decompressRLElist(self, nums: List[int]) -> List[int]:
        re = []
        tmp = 0
        count = 0
        for i in nums:
            if tmp == 0:
                count = i
            elif tmp == 1:
                re.extend([i]*count)
            tmp = (tmp+1) % 2
        return re
```
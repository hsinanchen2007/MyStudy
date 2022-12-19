### 解题思路
循环字典 如果值比上一个值大,就把key 和 value 都替换了. 最后返回key

### 代码

```python3
from collections import Counter
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        d = Counter(nums)
        i = 0
        while i < len(d):
            big = 0
            ans = 0
            for k, v in d.items():
                if v > big:
                    big = v
                    ans = k
            i += 1
        return ans


```
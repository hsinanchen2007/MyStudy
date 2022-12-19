### 解题思路
此处撰写解题思路

### 代码

```python3
import collections
class Solution:
    def majorityElement(self, nums: List[int]):
        c = collections.Counter(nums)
        return [i for i in c if c[i] > len(nums)//2][0]
```
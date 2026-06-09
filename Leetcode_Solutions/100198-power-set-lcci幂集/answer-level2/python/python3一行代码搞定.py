### 解题思路
python3一行代码

主要思路：将`[0: 2**len(nums)]`每个数考虑为二进制，对应位1为取，0为不取。

### 代码

```python3
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        return [[v for k, v in enumerate(nums) if (i>>k)&1] for i in range(2**len(nums))]
```
### 解题思路
分别处理再相加，算分治吗哈哈哈

### 代码

```python3
class Solution:
    def exchange(self, nums: List[int]) -> List[int]:
        odd = []
        ou = []
        for i in range(len(nums)):
            if nums[i]%2 == 0:
                ou.append(nums[i])
            else:
                odd.append(nums[i])
        return odd+ou
```
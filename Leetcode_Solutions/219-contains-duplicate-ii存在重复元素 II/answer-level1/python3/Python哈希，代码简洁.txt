### 解题思路
Python哈希，时间O(n),空间O(n)
如果找到了就返回true，否则就更新当前数字的index
### 代码

```python3
class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        mem = {}
        for i in range(0, len(nums)):
            j = mem.get(nums[i])
            if j is not None and i - j <= k:
                return True
            else:
                mem[nums[i]] = i
        return False
```
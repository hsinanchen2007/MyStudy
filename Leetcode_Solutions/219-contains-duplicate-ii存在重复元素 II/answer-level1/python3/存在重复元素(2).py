### 解题思路
这道题用哈希表来做非常简单，边创建边检查

### 代码

```python3
class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        hashtable = {}
        for i in range(len(nums)):
            if nums[i] in hashtable and i - hashtable[nums[i]] <= k:
                return True
            else:
                hashtable[nums[i]] = i
        return False

```
### 解题思路
维护一个哈希表
时间 O(n)
空间 O(n)

### 代码

```python3
class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        hashmap = {}
        for i in range(len(nums)):
            if nums[i] in hashmap and i - hashmap[nums[i]]<=k: return True
            hashmap[nums[i]] = i
        return False

```
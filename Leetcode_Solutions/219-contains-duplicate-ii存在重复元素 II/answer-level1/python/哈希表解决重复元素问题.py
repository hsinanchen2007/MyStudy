### 解题思路
哈希表解决重复元素问题，写的比较长，为了思路展示地更清晰

### 代码

```python3
class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        hash_, temp = {}, 0
        for i in nums:
            if i in hash_:
                if temp - hash_[i] <= k:
                    return True
                else:
                    hash_[i] = temp
                    temp += 1
            else:
                hash_[i] = temp
                temp += 1
        return False
```
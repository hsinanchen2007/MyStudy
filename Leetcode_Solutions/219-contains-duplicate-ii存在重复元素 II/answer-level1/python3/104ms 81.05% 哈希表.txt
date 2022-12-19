### 解题思路
创建一个哈希表，记录每种元素最新迭代的位置，
对每一个新元素，记录其序号
若哈希表中已经存在，比较其位置差异，并更新或返还true

### 代码

```python3
class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        hash = {}
        for i in range(len(nums)):
            if nums[i] in hash:
                if abs(hash[nums[i]] - i) <= k:
                    return True
                else:
                    hash[nums[i]] = i
            else:
                hash[nums[i]] = i
        return False

```
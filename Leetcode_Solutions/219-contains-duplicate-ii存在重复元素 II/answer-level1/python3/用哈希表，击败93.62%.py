### 解题思路
利用哈希表，将字典中没有的数字作为键，其索引作为值存入哈希表中，继续遍历数组，如果后面的数字在哈希表中，就计算索引的差，和k作比较，如果小于k，则满足题目要求，返回TRUE，如果不小于，有可能后面的会存在小于的情况，所以更新字典，继续遍历数组。如果遍历数组之后还没有相应的索引对，则返回FALSE。

### 代码

```python3
class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        dic={}
        for i in range(len(nums)):
            if nums[i] in dic:
                if abs(i-dic[nums[i]])<=k:
                     return True
                else:
                    dic[nums[i]]=i
            else:
                dic[nums[i]]=i
        return False
```
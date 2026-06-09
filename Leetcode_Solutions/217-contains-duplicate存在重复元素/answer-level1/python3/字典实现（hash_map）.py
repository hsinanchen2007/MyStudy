### 解题思路
查看key值，若存在返回真，其他为假

### 代码

```python3
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        hash_map={}
        for i in range(len(nums)):
            if nums[i] not in hash_map.keys():
                hash_map[nums[i]]=nums[i]
            else:
                return True
        return False
```
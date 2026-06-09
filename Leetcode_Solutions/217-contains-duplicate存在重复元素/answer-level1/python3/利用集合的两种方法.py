### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    
    def containsDuplicate(self, nums: List[int]) -> bool:
        """
        思路：利用集合，比较长度
        """
        if not nums:
            return False
        return not len(set(nums)) == len(nums)
        
    def containsDuplicate_set(self, nums: List[int]) -> bool:
        """
        思路：利用集合，进行查找
        """
        if not nums:
            return False
        record = set()
        for i in range(len(nums)):
            if nums[i] in record:
                return True
            record.add(nums[i])
        return False
```
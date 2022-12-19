### 解题思路
思路：利用字典存放每个元素的索引，在循环放入的过程中，就可以直接判断另一个元素是否在
        字典中，如果不在，则继续放入

### 代码

```python3
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        """
        思路：利用字典存放每个元素的索引，在循环放入的过程中，就可以直接判断另一个元素是否在
        字典中，如果不在，则继续放入
        """
        if not nums:
            return []
        record = dict()
        for i, num in enumerate(nums): # 使用一次循环
            component = target - num # 另一个待查的元素
            if component in record: # 如果这个待查元素已经存在于字典中，直接返回结果
                return [record.get(component), i]
            record[num] = i # 如果不在，则接着循环放入新的元素
        return []
```
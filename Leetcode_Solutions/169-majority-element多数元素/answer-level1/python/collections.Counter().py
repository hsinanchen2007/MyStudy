### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        import collections
        dict1 = collections.Counter(nums)
        for key,v in dict1.items():
            if v>len(nums)/2:
                return key

```
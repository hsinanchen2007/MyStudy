### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        from collections import Counter
        dic = Counter(nums)
        n = len(nums)//2
        for i in dic.keys():
            if dic[i] > n:
                return i
        return -1

```
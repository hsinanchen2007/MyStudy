### 解题思路

超过一半肯定是最多的。

### 代码一

```python []
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        return collections.Counter(nums).most_common(1)[0][0]
```

### 代码二

```python []
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        return max(c := collections.Counter(nums), key=c.__getitem__)
```

作弊作弊，用了Counter计数器

### 代码

```python
class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = collections.Counter(nums).most_common(1)
        return n[0][0]
```
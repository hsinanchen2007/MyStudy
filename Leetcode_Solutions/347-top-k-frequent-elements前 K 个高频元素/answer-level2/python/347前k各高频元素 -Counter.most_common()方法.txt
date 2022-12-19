### 解题思路
直接使用colletions中的Counter.most_common()方法，most_common(k)返回c出现最多的k项的元组列表，[(最高频元素，最高频次数),...,(最k频元素，最k频次数)]

### 代码

```python3
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        #Counter类
        from collections import Counter
        HT=Counter(nums)
        return [x[0] for x in HT.most_common(k)]
```
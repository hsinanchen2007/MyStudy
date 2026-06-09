### 解题思路
问题在于，可不可以用dic.key建堆呢？

### 代码

```python3
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        from collections import Counter
        import heapq
        dic = Counter(nums)
        return heapq.nlargest(k, dic.keys(), key=dic.get) 
        # res = []
        # for val in heapq.nlargest(k, dic.values()):
        #     item = [key for key in dic.keys() if dic[key] == val]
        #     res.extend(item)
        # return set(res)

```
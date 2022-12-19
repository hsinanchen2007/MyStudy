### 解题思路
先排序(O(nlogn))，然后pop最右侧两个值(O(1))比较, 
未消去就通过二分法插入到剩下的有序数组并保持有序（O(n))

### 代码

```python3
from bisect import insort_left

class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        stones.sort()
        while len(stones) > 1:
            r = stones.pop() - stones.pop()
            if r: insort_left(stones, r)
        return stones[0] if stones else 0
```
思路1：记录三个最大值

```python
class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        first = float("-inf")
        second = float("-inf")
        third = float("-inf")
        for num in nums:
            if num >= first:
                if num == first: continue
                first, second, third = num, first, second
            elif num >= second:
                if num == second: continue
                second, third = num, second
            elif num >= third:
                if num == third: continue
                third = num
        return third if third != float("-inf") else first
```

思路二：堆

```python
class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        import heapq
        visited = set()
        heap = []
        for num in nums:
            if num not in visited:
                visited.add(num)
                heapq.heappush(heap, num)
                if len(heap) > 3:
                    heapq.heappop(heap)
        return heapq.heappop(heap) if len(heap) == 3 else heap[-1]
```


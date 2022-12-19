```python
class Solution:
    def isPossibleDivide(self, nums: List[int], k: int) -> bool:
        nums.sort()
        dic = collections.defaultdict(int)
        for num in nums: dic[num] += 1
        for num in nums:
            while dic[num] != 0:
                for i in range(k):
                    if dic[num + i] == 0: return False
                    dic[num + i] -= 1
        return True
```

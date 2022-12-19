```python
class Solution:
    def canReorderDoubled(self, A: List[int]) -> bool:
        # even length
        # hashmap
        # A.length <= 30000
        # Time complexity : O(NlogN)
        # Space complexity: O(N)
        dic = collections.defaultdict(int)
        A.sort()
        for num in A: dic[num] += 1
        for key in dic:
            if dic[key] == 0: continue
            if key < 0:
                if key % 2 == 1 or dic[key // 2] < dic[key]:  return False
                dic[key // 2] -= dic[key]
            elif key > 0:
                if dic[key * 2] < dic[key]:  return False
                dic[key * 2] -= dic[key]
            else:
                if dic[key] % 2 == 1: return False
        return True
```
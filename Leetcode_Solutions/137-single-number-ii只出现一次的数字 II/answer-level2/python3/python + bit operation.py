```python
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        # each element apperas three time except for one
        # method1: Counter
        # Time complexity: O(N)
        # Space complexity: O(1)
        positive, negative = 0, 0
        for i in range(32):
            posCnt1, negCnt1 = 0, 0
            for num in nums:
                if num >= 0:
                    if num & (1 << i): posCnt1 += 1
                else:
                    if abs(num) & (1 << i): negCnt1 += 1
            if posCnt1 % 3 == 1:
                positive += 1 << i
            if negCnt1 % 3 == 1:
                negative += 1 << i
        return positive if positive else -negative
```
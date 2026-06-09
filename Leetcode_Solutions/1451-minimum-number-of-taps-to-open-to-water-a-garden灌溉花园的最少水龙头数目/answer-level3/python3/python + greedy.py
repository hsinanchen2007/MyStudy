```python
class Solution:
    def minTaps(self, n: int, ranges: List[int]) -> int:
        # start from 0
        # end to n
        # range(i - range[i], i + range[i])

        # 1 <= n <= 10 ** 4
        # ranges.length = n + 1
        # 0 <= ranges[i] <= 100
        
        # greed
        # Time complexity: O(n2)
        # Space complexity: O(n)

        taps = []
        for i, r in enumerate(ranges):
            taps.append((max(0, i - r), min(n, i + r)))
        taps.append([n, n])
        taps.sort(key = lambda x: x[0])
        left,right, i = 0, 0, 0
        res, temp_index = 0, 0
        flag = False
        while True:
            if i >= len(taps):break
            tap = taps[i]
            if tap[0] <= left: 
                if tap[1] > right:
                    right = tap[1]
                    flag = True
                    temp_index = i
            else:
                res += 1
                left = right
                if flag:
                    i = temp_index
                    flag = False
            i = i + 1
            
        return res if right == n else -1
```
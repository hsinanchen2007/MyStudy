### 解题思路
时间复杂度O(N)

### 代码

```python3
class Solution:
    def shortestSeq(self, big, small):
        from collections import Counter
        result = [float("inf"), float("inf")]
        left = 0
        n = len(big)
        small_set = set(small)
        cur_set = Counter()
        min_length = float("inf")
        for right in range(n):
            cur_set[big[right]] += 1
            while all(map(lambda x: x in cur_set and cur_set[x]>0, small_set)):
                if right - left + 1 < min_length:
                    min_length = right - left + 1
                    result[:] = [left, right]
                elif right - left + 1 == min_length and left < result[0]:
                    result[:] = [left, right]
                cur_set[big[left]] -= 1
                left += 1

        return result if result[0] != float("inf") else []
```
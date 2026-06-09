### 解题思路
桶排序，将非0值依次相加，只要和大于可容纳最多人数，则返回FALSE

### 代码

```python
class Solution(object):
    def carPooling(self, trips, capacity):
        buckets = [0] * 1001
        for c in trips:
            buckets[c[1]] += c[0]
            buckets[c[2]] -= c[0]
        i = 0
        cur_sum = 0
        while i < 1001:
            if buckets[i] != 0:
                cur_sum += buckets[i]
                if cur_sum > capacity:
                    return False
            i += 1
        return True
```
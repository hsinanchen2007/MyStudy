### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def twoSum(self, n):
        """
        :type n: int
        :rtype: List[float]
        """
        d = self.two_sum(0, n-1)
        sum = 0
        for v in d.values():
            sum += v
        for k, v in d.items():
            d[k] = v * 1.0 / sum
        sorted(d.items(), key=lambda x: x[1])
        return d.values()

    def two_sum(self, i, j):
        if i == j:
            return {1: 1.0, 2: 1.0, 3: 1.0, 4: 1.0, 5: 1.0, 6: 1.0}
        mid = (i + j) / 2
        d1 = self.two_sum(i, mid)
        d2 = self.two_sum(mid+1, j)
        return self.merge_two_sum(d1, d2)

    def merge_two_sum(self, d1, d2):
        if not d1:
            return d2
        if not d2:
            return d1
        d = dict()
        for k1, v1 in d1.items():
            for k2, v2 in d2.items():
                k = k1 + k2
                v = v1 * v2
                d[k] = d.get(k, 0) + v
        return d

```
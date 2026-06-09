### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def reorganizeString(self, S):
        """
        :type S: str
        :rtype: str
        """
        alpha_count = {}
        for s in S:
            alpha_count[s] = alpha_count.get(s, 0) + 1
        if max(alpha_count.values()) > (len(S) + 1) / 2:
            return ''
        heap, res = [(-c, a) for a, c in alpha_count.items()], ' '
        heapq.heapify(heap)
        while heap:
            count, alpha = heapq.heappop(heap)
            if res[-1] == alpha:
                tmp = (count, alpha)
                count, alpha = heapq.heappop(heap)
                res += alpha
                heapq.heappush(heap, tmp)
            else:
                res += alpha
            if count < -1:
                heapq.heappush(heap, (count + 1, alpha))
        return res[1:]
```
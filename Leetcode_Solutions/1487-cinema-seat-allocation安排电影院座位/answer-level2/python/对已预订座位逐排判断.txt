### 解题思路
先排序，然后将每排已预订作为摘出来判断是否影响就坐，影响的话就从可能的总数中减去。

### 代码

```python
class Solution(object):
    def maxNumberOfFamilies(self, n, reservedSeats):
        """
        :type n: int
        :type reservedSeats: List[List[int]]
        :rtype: int
        """
        reservedSeats.sort(key=lambda x: (x[0], x[1]))
        m, i = len(reservedSeats), 0
        ana = []
        ans = 2 * n
        while i < m:
            ana.append(reservedSeats[i][1])
            if i == m - 1 or reservedSeats[i][0] != reservedSeats[i+1][0]:
                length = len(ana)
                for k in range(length-1, -1, -1):
                    if ana[k] == 1 or ana[k] == 10:
                        ana.pop(k)
                        length -= 1
                flag = [1, 1, 1]
                for j in range(length):
                    if ana[j] in [2, 3, 4, 5]: flag[0] = 0
                    if ana[j] in [4, 5, 6, 7]: flag[1] = 0
                    if ana[j] in [6, 7, 8, 9]: flag[2] = 0
                flag_sum = sum(flag)
                if flag_sum == 0: ans -= 2
                elif flag_sum == 1 or flag_sum == 2: ans -= 1
                ana = []
            i += 1
        return ans
```
### 解题思路

统计各个年份的生死人数，对年份进行去重排序遍历。

### 代码

```python []
class Solution:
    def maxAliveYear(self, birth: List[int], death: List[int]) -> int:
        b = collections.Counter(birth)
        d = collections.Counter(death)
        ans, maxcount, cur = 0, 0, 0
        for year in sorted({*b.keys(), *d.keys()}):
            cur += b[year]
            if cur > maxcount:
                maxcount = cur
                ans = year
            cur -= d[year]
        return ans
```
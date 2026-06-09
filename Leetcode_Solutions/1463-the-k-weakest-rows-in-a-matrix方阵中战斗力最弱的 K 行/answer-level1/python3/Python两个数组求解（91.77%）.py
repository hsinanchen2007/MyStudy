**要点**：
- 一个powers数组记录战斗力，一个res数组记录对应的index
- powers数组通过二分搜索（bisect）插入，res对应位置插入index
- 最后返回res前k个元素即可

**复杂度分析**：
- 时间：遍历m行，每行最多n个元素，二分搜索log(m)，最后总的是O(m(n + log(m)))=O(mn)
- 空间：两个数组O(2m)

```
import bisect
class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        powers = []
        res = []
        for index, row in enumerate(mat):
            power = 0
            for i in row:
                if i: power += 1
                else: break
            
            addPosition = bisect.bisect(powers, power)
            powers.insert(addPosition, power)
            res.insert(addPosition, index)

        return res[:k]
```

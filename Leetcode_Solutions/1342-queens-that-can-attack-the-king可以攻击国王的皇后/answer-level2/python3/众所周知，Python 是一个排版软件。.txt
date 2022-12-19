### 解题思路

直接从 [车的可用捕获量](https://leetcode-cn.com/problems/available-captures-for-rook/solution/zhong-suo-zhou-zhi-python-shi-yi-ge-pai-ban-ruan-j/) 搬代码。

### 代码

```python3
class Solution:
    def queensAttacktheKing(self, queens: List[List[int]], king: List[int]) -> List[List[int]]:
        rx, ry = king
        ans = []
        def findp(x, y, x_step, y_step):
            if x < 0 or x > 7 or y < 0 or y > 7:
                return
            if [x, y] in queens:
                ans.append([x, y])
            else:
                findp(x + x_step, y + y_step, x_step, y_step)
        findp(rx, ry, -1, 0)
        findp(rx, ry, 1, 0)
        findp(rx, ry, 0, -1)
        findp(rx, ry, 0, 1)
        findp(rx, ry, 1, 1)
        findp(rx, ry, 1, -1)
        findp(rx, ry, -1, 1)
        findp(rx, ry, -1, -1)
        return ans
```
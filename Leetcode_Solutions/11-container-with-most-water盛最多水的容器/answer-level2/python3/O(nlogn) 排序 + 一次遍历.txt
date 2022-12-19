### 解题思路

从大到小排序
维护三个变量： 
当前的最低高度，当前最左，当前最右
最大面积就是 当前高度 × （当前最右 - 当前最左）

### 代码

```python
class Solution:
    def maxArea(self, height: List[int]) -> int:
        x = []
        for i, n in enumerate(height):
            x.append((i, n))
        x.sort(key=lambda x:x[1], reverse=True)
        h = min(x[0][1], x[1][1])
        l = min(x[0][0], x[1][0])
        r = max(x[0][0], x[1][0])
        ans = h * (r - l)
        for i in range(2, len(x)):
            l = min(x[i][0], l)
            r = max(x[i][0], r)
            h = min(h, x[i][1])
            ans = max(ans, h * (r - l))
        return ans

```
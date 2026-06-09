### 解题思路
能在中间拦截说明到终点的曼哈顿距离有“不大于”的关系（到拦截点，然后再最短路径走向终点，这个距离一定不小于直接最短路径） 所以True对应“大于”的关系

### 代码

```python3
# https://leetcode-cn.com/problems/escape-the-ghosts/

class Solution:
    def dist(self, p1, p2):
        return sum([abs(p1[i] - p2[i]) for i in range(len(p1))])

    def escapeGhosts(self, ghosts: List[List[int]], target: List[int]) -> bool:
        return min(self.dist(target, ghost) for ghost in ghosts) > self.dist(target, [0, 0])
```
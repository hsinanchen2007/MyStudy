### 解题思路
类似题目可以参考[994.腐烂的橘子](https://leetcode-cn.com/problems/rotting-oranges/)
其实不需要向四个方向，只需要考虑 左->右 和 上->下 两种情况
用set存储已经遍历过的路径
注意回溯的条件即可
### 代码

```python3
class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        go = [(0, 1), (1, 0)] #只需要考虑两个移动方向
        global num
        num = 0
        checked = set() #不重复元素集，用于记录已经走过的路

        def dfs(x, y): 
            global num
            if x >= m or y >= n or (x, y) in checked or sum(map(int, str(x)+str(y))) > k:#回溯条件
                return
            checked.add((x, y))
            num += 1
            for i, j in go:
                new_x, new_y = x + i, y + j
                dfs(new_x, new_y)

        dfs(0, 0)
        return num
```
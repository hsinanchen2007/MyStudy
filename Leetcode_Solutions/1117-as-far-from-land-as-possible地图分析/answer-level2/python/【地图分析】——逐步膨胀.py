这道题换个思路就很简单了——
以原[陆地]区域为中心，逐步向外扩张/膨胀；每次[对外]扩张/膨胀，只考虑最外围的每个坐标的 👆 👇 👈 👉 4 个方向是否为 [海洋] 区域。知道所有[海洋区域]被[占领]。
这个过程中，每次迭代，海洋到陆地的最小距离 +1，并且对于所有[大陆块]都是一样的最小距离，因此不必担心重叠问题。

```python
class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        N = len(grid)
        if N == 1:
            return -1
        
        cnt0 = 0
        cnt1 = 0

        ceil_tocheck = set()    # 在下面的 while 循环中要检查的坐标的集合
        ceil_unchecked = set()  # 剩下未检查的[海洋]的坐标集合
        flags = [[False for j in range(N)] for i in range(N)] # 一个[标记]矩阵，同 grid 等大，用来记录[该坐标]是否经过检查了

        for i in range(N):
            for j in range(N):
                if grid[i][j] == 0:
                    cnt0 += 1
                    ceil_unchecked.add((i, j)) # 初始化，未检查的[海洋]的坐标集合包括所有的[海洋]区域
                else:
                    cnt1 += 1
                    ceil_tocheck.add((i, j))   # 初始化，首先从原[陆地]区域开始向外[膨胀]
                    flags[i][j] = True         # 对[膨胀]的起点设置标记
        
        # 根据题意，全部[陆地]或者全部[海洋]，返回 -1
        if cnt0 == N**2 or cnt1 == N**2:
            return -1
        
        dist = 0
        while ceil_unchecked: # 到所有的坐标都被检查过为止
            dist += 1

            ceil_tocheck_t = set()             # 用于储备下一轮的[膨胀]起点的坐标

            # 遍历档次迭代中每一个待检查的坐标
            for (i, j) in ceil_tocheck:
                # 依次考虑它的[上][下][左][右]是否为海洋，且未被标记
                # top
                if i > 0 and not flags[i-1][j]:
                    flags[i-1][j] = True
                    ceil_tocheck_t.add((i-1, j))
                    ceil_unchecked.remove((i-1, j))
                # down
                if i < N-1 and not flags[i+1][j]:
                    flags[i+1][j] = True
                    ceil_tocheck_t.add((i+1, j))
                    ceil_unchecked.remove((i+1, j))
                # left
                if j > 0 and not flags[i][j-1]:
                    flags[i][j-1] = True
                    ceil_tocheck_t.add((i, j-1))
                    ceil_unchecked.remove((i, j-1))
                # right
                if j < N-1 and not flags[i][j+1]:
                    flags[i][j+1] = True
                    ceil_tocheck_t.add((i, j+1))
                    ceil_unchecked.remove((i, j+1))
            
            ceil_tocheck = ceil_tocheck_t # 更新下一次迭代中要检查的坐标的集合
        
        return dist
```
- 使用哈希可以高效做到：检查存在性、移除（哈希的时间的复杂度为 O(1);
- 前半部分的时间复杂度为 O(N^2)；后半部分时间复杂度为 O(N).

关键在于如何判断两个岛屿相同；
# 1) bfs 相对平衡的四叉树
把一个岛屿想象成一颗树，根节点就是左上角的节点；
这棵树有四个孩子，up, down, left, right
对应方向有相邻岛屿，则认为有孩子；否则对应孩子为none；
这样给每个结点进行编码，
用level表示树的层数，用idx表示孩子的种类，idx [1...4]表示up, down, left, right
遍历方式类似于树的层次遍历；根节点是1，第一层节点为2，3，4，5，以此类推

举例：
```
11000
11000
00011
00011
```
两个岛屿的编码方式均为：['1#2#4#8#', '1#2#4#8#']
1#2#4#8#

1代表根节点(0,0) level = 0
2代表节点(1,0) level = 1
4代表节点(0,1) level = 2
8代表节点(1,1) level = 3

```
class Solution:
    def numDistinctIslands(self, grid: List[List[int]]) -> int:
        if not grid or not grid[0]:
            return 0
        R = len(grid)
        C = len(grid[0])
        def inArea(r, c):
            if r >= 0 and r < R and c >= 0 and c < C:
                return True
            return False

        # 以r，c为起点的为访问所有未访问的相邻岛屿，返回编码值
        def bfs(r, c, idx):
            queue = [(r, c, idx)]
            code = ""
            grid[r][c] = 2
            while queue:
                r, c, idx = queue.pop(0)
                code += str(idx) + '#'
                # 清零
                offset = 1
                for r0, c0 in ((-1, 0), (1, 0), (0, -1), (0, 1)):
                    nr = r0 + r
                    nc = c0 + c
                    if inArea(nr, nc) and grid[nr][nc] == 1:
                        grid[nr][nc] = 2
                        queue.append((nr, nc, (idx - 1) * 4 + offset))
                    offset += 1 
            return code
        
        ret = []
        for r in range(R):
            for c in range(C):
                if grid[r][c] == 1:
                    ret.append(bfs(r, c, 1)) 
        print(ret)
        return len(set(ret))                     
```
# 2) dfs 很不平衡的四叉树
根据dfs的轨迹进行编码
根据level和方向进行编码, [level:direction#level:direction1#,...]
举例：
```
11000
11000
00011
00011
```
['0:1#1:1#2:3#3:0#', '0:1#1:1#2:3#3:0#']
0:1 代表(0,0) 
1:1 代表(1,0)
2:3 代表(1,1)
3:0 代表(0,1)
```
class Solution:
    def numDistinctIslands(self, grid: List[List[int]]) -> int:
        if not grid or not grid[0]:
            return 0
        R = len(grid)
        C = len(grid[0])
        def inArea(r, c):
            if r >= 0 and r < R and c >= 0 and c < C:
                return True
            return False


        # 以r，c为起点的为访问所有未访问的相邻岛屿，返回编码值
        def dfs(r, c, level, idx):
            if not inArea(r, c) or grid[r][c] != 1:
                return ""           
            grid[r][c] = 2
            ret = str(level) + ':' + str(idx) + '#'
            idx = 0
            for r0, c0 in ((-1, 0), (1, 0), (0, -1), (0, 1)):
                nr = r0 + r
                nc = c0 + c
                ret += dfs(nr, nc, level + 1, idx)
                idx += 1         
            return ret
        ret = []
        for r in range(R):
            for c in range(C):
                if grid[r][c] == 1:
                    ret.append(dfs(r, c, 0, 1)) 
        print(ret)
        return len(set(ret))
```

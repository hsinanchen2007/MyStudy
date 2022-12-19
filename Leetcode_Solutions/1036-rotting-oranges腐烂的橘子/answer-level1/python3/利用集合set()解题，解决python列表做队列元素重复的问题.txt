### 解题思路
用集合的非重复特性解决这一问题。
对于任一时间点，当前橘子有三个集合：腐烂的橘子rot、新鲜的橘子fresh以及正在腐烂的橘子trans。
正在腐烂的橘子是指与腐烂的橘子相邻的新鲜橘子；
集合一和集合二交集为空；集合三是集合二的子集。

在时间点t内，正在腐烂的橘子trans从新鲜的橘子fresh中剥离，同时加入腐烂的橘子rot
当fresh集合为空时，返回时间t;
当正在腐烂的橘子为空，而新鲜的橘子不为空时，说明不会全部腐烂，返回-1

思路很简单，但是似乎时间和空间上不够简单。。。哪位帮着看看算法复杂度？
### 代码

```python3
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        rot=set()
        fresh=set()
        trans=set()
        t=0
        # 找到所有橘子
        for i in range(0,len(grid)):
            for j in range(0,len(grid[0])):
                if grid[i][j]==2:
                    rot.add((i,j))
                elif grid[i][j]==1:
                    fresh.add((i,j))
        # 找到与腐烂橘子直接相连的新鲜橘子
        while len(fresh)!=0:
            t+=1
            for p in fresh:
                for q in rot:
                    if abs(p[0]-q[0])+abs(p[1]-q[1])==1:
                        trans.add(p)
            if len(trans)==0: return -1
            fresh=fresh-trans
            rot=rot|trans
            trans.clear()
        else:
            return t

```
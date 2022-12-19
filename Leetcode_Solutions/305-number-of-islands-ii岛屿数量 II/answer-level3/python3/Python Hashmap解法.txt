# 1. 思路：

1. 用 m × n 的列表 **grid 保存岛屿信息**，其中0表示为海洋，非0数字表示岛屿的编号，**同一块岛屿应该具有相同的编号值**。

2. 用哈希表 **island 保存不同岛屿编号所对应的岛屿坐标 (x, y)**

3. **当两块编号不同的岛屿被某点连接起来后，更新列表 grid 中整块岛屿的编号值，更新哈希表 island 中岛屿编号所对应的坐标值，并将空的岛屿编号删除**

4. 针对每次添加操作，其**岛屿的个数即为哈希表 island 的长度**。

# 2. 代码

```
def numIslands2(self, m: int, n: int, positions: List[List[int]]) -> List[int]:
    
    grid = [[0]*n for _ in range(m)]              # 构建保存岛屿的表格
    island = collections.defaultdict(set)         # 保存岛屿编号和坐标的哈希表

    directions = [(1,0),(-1,0),(0,-1),(0,1)]      # 上下左右四个方向

    index = 1                                     # 初始化岛屿编号

    res = []

    for x,y in positions:                         # 对每个位置进行遍历
        if grid[x][y]:                            # 如果该位置已经有岛屿编号
            res.append(len(island))               # 直接在结果中添加当前哈希表的长度
            continue                              # 跳过

        mark = []                                 # 记录上下左右四个岛屿的编号
        for dx,dy in directions:                  # 对上下左右进行遍历
                                                  # 当坐标合法，且该坐标为岛屿时，加入mark
                                                  # 为防止有重复值出现，需要判断该值是否在mark中
            if 0<=x+dx<m and 0<=y+dy<n and grid[x+dx][y+dy] and grid[x+dx][y+dy] not in mark:
                mark.append(grid[x+dx][y+dy])
        
        if len(mark)==0:                          # mark为空，即上下左右都为海洋
            grid[x][y] = index                    # 更新该点在grid中的值
            island[index].add((x,y))              # 更新哈希表island
            index += 1                            # index + 1
        
        else:
            temp = mark[0]                        # 如果mark不为空，将mark中所有的岛屿编号统一
            grid[x][y] = temp                     # 设定mark[0]，即temp为统一值
            island[temp].add((x,y))               # 更新grid[x][y]和哈希表island

            for num in mark[1:]:                  # 对于mark中的其他岛屿编号
                for i,j in island[num]:           # 从哈希表中取出其所有点的坐标i,j
                    grid[i][j] = temp             # 更新grid[i][j]
                island[temp] |= island[num]       # 更新temp所对应的哈希表，将num对应的坐标加入其中
                del island[num]                   # 删除哈希表中num的条目

        res.append(len(island))                   #在结果中添加当前哈希表island的长度
    
    return res
```

# 3. 结果


![微信截图_20200110094753.png](https://pic.leetcode-cn.com/869f9f6931716e0ec44c310ae8a60beb85a34dcc96c58b02d111e51f6bc96447-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200110094753.png)


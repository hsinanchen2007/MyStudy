解题思路：
1、遍历距离陆地为1的所有0(靠近岸边的0)
2、将这些0赋值为1
3、重复1、2直到地图中没有0为止
最后，重复的次数就是最远0到岸边的距离

以下为python代码：
```
n = len(grid)
res = 0 # 结果初始为0
while True:
    lines = [] #临时存储每轮遍历岸边的0
    for i in range(n):
        for j in range(n):
            if grid[i][j] == 0:
                # 四个方向只要有1，就记录并继续
                if 0 <= i-1 < n and 0 <= j < n and grid[i - 1][j] == 1:
                    lines.append((i, j))
                    continue
                if 0 <= i < n and 0 <= j-1 < n and grid[i][j-1] == 1:
                    lines.append((i, j))
                    continue
                if 0 <= i+1 < n and 0 <= j < n and grid[i + 1][j] == 1:
                    lines.append((i, j))
                    continue
                if 0 <= i < n and 0 <= j+1 < n and grid[i][j + 1] == 1:
                    lines.append((i, j))
                    continue
    if lines: # 本次遍历如果有内容，结果+1
        res += 1
    else: # 如果没有内容，说明地图已经没有0了
        if res: # 有值返回该值，为0返回-1
            return res
        return -1
    # 将岸边的0赋值为1
    for x, y in lines:
        grid[x][y] = 1
```


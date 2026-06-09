```python
    def trapRainWater(self, heightMap: List[List[int]]) -> int:
        # 整体是初始化最外围一圈的围栏，模拟围栏外的水不停上涨往里灌的过程
        if not heightMap:
            return 0
        m, n, border = len(heightMap), len(heightMap[0]), []
        for i in range(m):
            border += [(heightMap[i][0], i, 0), (heightMap[i][n-1], i, n-1)]
            heightMap[i][0] = heightMap[i][n-1] = -1  # 标记已访问
        for j in range(1, n-1):
            border += [(heightMap[0][j], 0, j), (heightMap[m-1][j], m-1, j)]
            heightMap[0][j] = heightMap[m-1][j] = -1  # 标记已访问

        heapq.heapify(border)  # 将初始围栏放入以堆存放的优先队列，方便当前围栏最矮处即水的入口
        res, _h = 0, float('-inf')  # res为答案，_h为当前的水位
        while border:
            h, i, j = heapq.heappop(border)  # 找到围栏的入口
            _h = max(_h, h)  # 如果围栏最矮处变高了水位就涨到该高度
            for _i, _j in ((i-1, j), (i+1, j), (i, j-1), (i, j+1)):  # 通过bfs来收缩围栏
                if 0 < _i < m-1 and 0 < _j < n-1 and heightMap[_i][_j] != -1:  # 未访问过，将围栏往内收缩
                    res += max(0, _h-heightMap[_i][_j])  # 如果小于当前围栏则表示该格子可以储水
                    heapq.heappush(border, (heightMap[_i][_j], _i, _j))  # 将其继续加入围栏的优先队列用于继续bfs
                    heightMap[_i][_j] = -1  # 标记已访问
        return res
```

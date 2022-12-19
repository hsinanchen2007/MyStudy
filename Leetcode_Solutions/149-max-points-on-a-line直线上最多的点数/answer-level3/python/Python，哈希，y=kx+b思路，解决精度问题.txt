很容易想到哈希，坐标相同的点加上点的index区分就是了。

python主要的问题是要处理好精度问题
```python
    def maxPoints(self, points: list) -> int:
        if len(points) < 3:
            return len(points)

        lines, p_visited = {}, set()  # 记录每个直线所含的点以及当前已访问过的点
        for i, (x, y) in enumerate(points):  # 因为有重复点所以得加上其下标作为唯一标识
            for (_x, _y, j) in p_visited:  # 尝试与每个访问过的结点构造直线
                k, _k, b = None, None, x  # 斜率为正无穷大时的特殊情况
                if _x != x:  # 求其y=kx+b的参数k, b
                    k = (_y-y)/(_x-x)
                    _k = (_x-x)/(_y-y) if _y != y else None  # 为修正python的精度问题， 用k的倒数作为参数的补充
                    b = round(y-k*x, 6)  # 同样用来修正python的精度问题
                lines[(k, _k, b)] = lines.get((k, _k, b), set()) | {(x, y, i), (_x, _y, j)}  # 将结点加入该参数确定的直线
            p_visited.add((x, y, i))  # 加入访问过的列表
        return max(len(x) for x in lines.values())
```

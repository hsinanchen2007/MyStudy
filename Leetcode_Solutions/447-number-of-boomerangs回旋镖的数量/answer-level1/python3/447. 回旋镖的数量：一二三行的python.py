![image.png](https://pic.leetcode-cn.com/fa360d2978b6234ba4ca1085efcc81f4fe2e0d11f6e368c393025989d599b54b-image.png)

遍历点点组合，统计距离到某点相等的数量，然后根据组合公式求解子和，最后再累和，其实写成两行一行问题也不大，就是太长了，其中两行版最快，一行版最慢，要2000ms+。

三行版：

```python []
class Solution:
    def numberOfBoomerangs(self, points: List[List[int]]) -> int:
        def f(x1, y1):
            d = collections.Counter((x2 - x1) ** 2 + (y2 - y1) ** 2 for x2, y2 in points)
            return sum(t * t - t for t in d.values())
        return sum(f(x1, y1) for x1, y1 in points)
```

两行版：

```python [0]
class Solution:
    def numberOfBoomerangs(self, points: List[List[int]]) -> int:
        f = lambda x1, y1: sum(t * t - t for t in collections.Counter((x2 - x1) ** 2 + (y2 - y1) ** 2 for x2, y2 in points).values())
        return sum(f(x1, y1) for x1, y1 in points)
```

一行版：

```python [1]
class Solution:
    def numberOfBoomerangs(self, points: List[List[int]]) -> int:
        return sum(sum(t * t - t for t in collections.Counter((x2 - x1) ** 2 + (y2 - y1) ** 2 for x2, y2 in points).values()) for x1, y1 in points)
```
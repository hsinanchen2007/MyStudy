### 解题思路
首先要清楚如果位置编号最大的是蓝色那么整个灯都是蓝色的，因此我们只要判断是否目前出现的最大号的灯是蓝色的。
考虑并查集，每次新添加一盏灯，假设位置是pos，那么我们就将pos-1，pos，pos+1合并起来，准确的说就是将左边或者右边出现的部分合并起来。
每次添加完之后都去检查最大号的灯是否和最小号的灯在一个并查集当中即可。

### 代码

```python3
class Solution:
    def find(self, x: int, f: List[int]) -> int:
        if x == f[x]:
            return f[x]
        else:
            f[x] = self.find(f[x], f)
            return f[x]

    def numTimesAllBlue(self, light: List[int]) -> int:
        light_len = len(light)
        f = [i for i in range(0, light_len + 1)]
        vis = [False  for i in range(0, light_len + 1)]
        res = 0
        max_light_pos = 0

        vis[0] = True
        for pos in light:
            max_light_pos = max(pos, max_light_pos)
            vis[pos] = True

            if vis[pos - 1]:
                father = self.find(pos - 1, f)
                f[pos] = father

            if pos + 1 <= light_len and vis[pos + 1]:
                right_father = self.find(pos + 1, f)
                f[right_father] = f[pos]

            if self.find(0, f) == self.find(max_light_pos, f):
                res += 1
        return res
```
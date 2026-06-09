# 基本思想
1. 需要先把所有矩形切割成在横坐标互不相交的小矩形，例如：矩形1(x1 = 6, x2 = 10)，矩形2(x1 = 8, x2 = 12)，我们就可以分割成：矩形1(x1 = 6, x2 = 8)，矩形2(x1 = 8, x2 = 10)，矩形3(x1 = 10, x2 = 12)
2. 然后我们再把段相同(即x1, x2相同)的矩形放一起，继续进行判断。例如：矩形1(y1, y2)，矩形2(y3, y4)，如果y2 < y3，则两矩形不相交，res += 面积1 + 面积2；如果y2 > y3 and y4 > y2，则res += 面积1 + (面积2中不相交的区域)；如果y2 > y4，则res += 面积1。

```
class Solution:
    def rectangleArea(self, rectangles: List[List[int]]) -> int:
        mod = 10 ** 9 + 7
        
        x_set = set()
        # 收集横坐标
        for x1, y1, x2, y2 in rectangles:
            x_set.update([x1, x2])
        # 用收集好的横坐标，切割矩形（思想1）
        x_list = sorted(list(x_set))
        index = {v: k for k, v in enumerate(x_list)}
        dp = collections.defaultdict(dict) # 用于存储x段相同的矩形
        for x1, y1, x2, y2 in rectangles:
            i, j = index[x1], index[x2]
            for k in range(i, j):
                dp[x_list[k], x_list[k + 1]][y1] = max(dp[x_list[k], x_list[k + 1]].get(y1, 0), y2) # 只需要记录同底矩形的最高长度     
        
        res = 0
        # 合并y轴重合矩形（思想2）
        for x in dp:
            cur = 0
            for y in sorted(dp[x].keys()):
                if cur < dp[x][y]:
                    if y < cur:
                        res += (dp[x][y] - cur) * (x[1] - x[0])
                    else:
                        res += (dp[x][y] - y) * (x[1] - x[0])
                    cur = dp[x][y]
            res %= mod
        
        return res
```
本人菜鸟一枚，思想提供来源“小白二号”。
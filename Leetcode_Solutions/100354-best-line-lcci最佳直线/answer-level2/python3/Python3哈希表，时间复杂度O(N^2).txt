# 解题思路：
1. 用一个字典保存已找到的所有直线的出现次数，和其穿过的下标最小的两个点的下标
2. 遍历所有点对，更新字典及最优解

# 复杂度分析：
1. 时间复杂度：O(n^2)
2. 空间复杂度：O(n^2)

# 代码实现：
```
class Solution:
    def bestLine(self, points: List[List[int]]) -> List[int]:
        d = {}
        x = y = 0
        maxCount = 0
        for i in range(len(points)):
            for j in range(i+1, len(points)):
                k, b = self.f([points[i], points[j]])
                if (k, b) in d.keys():
                    d[(k, b)][0] += 1
                else:
                    d[(k, b)] = [1, (i, j)]
                if d[(k, b)][0] > maxCount or (d[(k, b)][0] == maxCount and d[(k, b)][1][0] < x) or (d[(k, b)][0] == maxCount and d[(k, b)][1][1] < y):
                    maxCount = d[(k, b)][0]
                    x, y = d[(k, b)][1]
                print(x, y)
        return [x, y]

    # 求两点之间连线的k和b
    def f(self, points: List[List[int]]) -> List[int]:
        if points[0][0] == points[1][0]:
            return [float('inf'), points[0][0]]
        else:
            return [(points[1][1]-points[0][1]) / (points[1][0]-points[0][0]),
            (points[0][1]*points[1][0]-points[1][1]*points[0][0]) / (points[1][0]-points[0][0])]
```
### 解题思路
题目中所谓的 "回旋镖" 就是指数组中存在两个点 B C 与点 A 的距离相等。 即 [A, B, C] 中 distance(A, B) == distance(A, C)，  [A, B, C] 就是一个 "回旋镖" 
题目中要求返回满足该条件的所有点的个数， 所以可以想到固定点 A， 并计算其它所有点到 A 的距离，并在字典 distNum 中记录（k 为距离， v 为是距离为 k 的点的数量） 
然后再检查 distNum， 如果同一个距离有两个或以上的点， 就可以说明存在 "回旋镖".
并且通过简单的画图总结， 可以知道回旋镖的数量为 distNum[d] * (distNum[d] - 1) 即：
..... 
4 个与点 A 相同距离的点， 则有 4 * 3 个回旋镖 
3 个与点 A 相同距离的点， 则有 3 * 2 个回旋镖 
2 个与点 A 相同距离的点， 则有 2 * 1 个回旋镖 

时间复杂度 O(n²)， 空间复杂度 O(n)

### 代码

```python
class Solution(object):
    def numberOfBoomerangs(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        distNum = dict() # 用来记录数组中其它的点到点 p 的距离， k 为距离的数值， v 是距离为 k 的点的数量
        res = 0
        for i in xrange(len(points)): # 两层循环， 时间复杂度 O(n²)，
            distNum.clear() # 每次循环复用字典， 所以空间复杂度 O(n)
            for j in xrange(len(points)):
                if i == j:
                    continue
                # 为了防止浮点精度丢失的问题， 所以这里没有进行开方， 因为只需要找到距离相等的点就可以， 不需要求实际的距离
                dist = (points[i][0] - points[j][0]) ** 2 + (points[i][1] - points[j][1]) ** 2  # 题目中说明坐标在闭区间 [-10000, 10000] 中， 所以此处平方和不会整形移除（int32）
                if dist not in distNum:
                    distNum[dist] = 1
                else:
                    distNum[dist] += 1
            for d in distNum:
                    res += distNum[d] * (distNum[d] - 1)
        return res
```
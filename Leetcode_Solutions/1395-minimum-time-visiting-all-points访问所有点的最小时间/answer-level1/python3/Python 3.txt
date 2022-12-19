膨胀了，居然要发题解了，，，

问题的核心是归纳出两点之间的距离 为 纵横坐标中大的那个，代码就简单了。

对初学者来讲，可能难的还在于range的范围，数组下标的范围。


class Solution:
    def minTimeToVisitAllPoints(self, points: List[List[int]]) -> int:
        s=0
        for i in range(len(points)-1):
            s += max(abs(points[i+1][0]-points[i][0]),abs(points[i+1][1]-points[i][1]))
        return s
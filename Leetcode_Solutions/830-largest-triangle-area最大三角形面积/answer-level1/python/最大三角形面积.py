#### 枚举：

我们可以枚举每一个三角形，计算面积并找出最大的面积值。根据三角形的三个顶点计算出面积的方法有很多种：

* [鞋带公式](https://blog.csdn.net/c___c18/article/details/89284965)，用于计算任意多边形的面积，可用于计算三角形的面积；

* [海伦公式](https://baike.baidu.com/item/%E6%B5%B7%E4%BC%A6%E5%85%AC%E5%BC%8F)，从三个顶点得到三边长，并使用海伦公司计算出面积；

* 三角形面积公式 `S = 1/2 * a * b * sin(C)`，首先得到两边的长度，通过叉积算出夹角的正弦值，并使用公式计算出面积。

下面的代码中使用的是鞋带公式计算三角形的面积。

```Java [sol1]
class Solution {
    public double largestTriangleArea(int[][] points) {
        int N = points.length;
        double ans = 0;
        for (int i = 0; i < N; ++i)
            for (int j = i+1; j < N; ++j)
                for (int k = j+1; k < N; ++k)
                    ans = Math.max(ans, area(points[i], points[j], points[k]));
        return ans;
    }

    public double area(int[] P, int[] Q, int[] R) {
        return 0.5 * Math.abs(P[0]*Q[1] + Q[0]*R[1] + R[0]*P[1]
                             -P[1]*Q[0] - Q[1]*R[0] - R[1]*P[0]);
    }
}
```

```Python [sol1]
class Solution(object):
    def largestTriangleArea(self, points):
        def area(p, q, r):
            return .5 * abs(p[0]*q[1]+q[0]*r[1]+r[0]*p[1]
                           -p[1]*q[0]-q[1]*r[0]-r[1]*p[0])

        return max(area(*triangle)
            for triangle in itertools.combinations(points, 3))
```

**复杂度分析**

* 时间复杂度：$O(N^3)$，其中 $N$ 是数组 `points` 的长度。

* 空间复杂度：$O(1)$。
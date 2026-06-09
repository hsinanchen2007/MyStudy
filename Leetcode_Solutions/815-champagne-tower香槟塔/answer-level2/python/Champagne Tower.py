#### 方法一：模拟

我们可以直接模拟整个过程。我们记录流入每个杯子的香槟的数量之和，例如对于一个杯子，流入的香槟数量为 `10`。由于这个数值大于 `1`，因此会有 `9` 数量的香槟流出这个杯子，并且会有 `4.5` 数量的香槟分别流入这个杯子下面的两个杯子中。以此类推。

总的来说，如果流入一个杯子的香槟数量为 `X`，且 `X` 大于 `1`，那么就会有 `Q = (X - 1.0) / 2` 数量的香槟流入下面的两个杯子中。我们可以从第一层的杯子开始，计算出第二层每个杯子中流入的香槟数量，再计算出第三层的数量，直到计算到第 `query_row` 层。

```Java [sol1]
class Solution {
    public double champagneTower(int poured, int query_row, int query_glass) {
        double[][] A = new double[102][102];
        A[0][0] = (double) poured;
        for (int r = 0; r <= query_row; ++r) {
            for (int c = 0; c <= r; ++c) {
                double q = (A[r][c] - 1.0) / 2.0;
                if (q > 0) {
                    A[r+1][c] += q;
                    A[r+1][c+1] += q;
                }
            }
        }

        return Math.min(1, A[query_row][query_glass]);
    }
}
```

```Python [sol1]
class Solution(object):
    def champagneTower(self, poured, query_row, query_glass):
        A = [[0] * k for k in xrange(1, 102)]
        A[0][0] = poured
        for r in xrange(query_row + 1):
            for c in xrange(r+1):
                q = (A[r][c] - 1.0) / 2.0
                if q > 0:
                    A[r+1][c] += q
                    A[r+1][c+1] += q

        return min(1, A[query_row][query_glass])
```

**复杂度分析**

* 时间复杂度：$O(R^2)$，其中 $R$ 是杯子的层数。

* 空间复杂度：$O(R^2)$。
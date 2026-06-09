#### 方法 1：遍历矩阵

**想法和算法**

对于矩阵中的每一个单元格，找所有 9 个包括它自身在内的紧邻的格子。

然后，我们要将所有邻居的和保存在 `ans[r][c]` 中，同时记录邻居的数目 `count`。最终的答案就是和除以邻居数目。

```Python []
class Solution(object):
    def imageSmoother(self, M):
        R, C = len(M), len(M[0])
        ans = [[0] * C for _ in M]

        for r in xrange(R):
            for c in xrange(C):
                count = 0
                for nr in (r-1, r, r+1):
                    for nc in (c-1, c, c+1):
                        if 0 <= nr < R and 0 <= nc < C:
                            ans[r][c] += M[nr][nc]
                            count += 1
                ans[r][c] /= count

        return ans
```

```Java []
class Solution {
    public int[][] imageSmoother(int[][] M) {
        int R = M.length, C = M[0].length;
        int[][] ans = new int[R][C];

        for (int r = 0; r < R; ++r)
            for (int c = 0; c < C; ++c) {
                int count = 0;
                for (int nr = r-1; nr <= r+1; ++nr)
                    for (int nc = c-1; nc <= c+1; ++nc) {
                        if (0 <= nr && nr < R && 0 <= nc && nc < C) {
                            ans[r][c] += M[nr][nc];
                            count++;
                        }
                    }
                ans[r][c] /= count;
            }
        return ans;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 是图片中像素的数目。我们需要将每个像素都遍历一遍。

* 空间复杂度：$O(N)$，我们答案的大小。

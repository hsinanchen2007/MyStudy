####  方法一：
我们可以转换一下思想：每增加一行，角矩形的数量增加了多少。

**算法：**
我们用 `count[i, j]` 来记录 `row[i] = row[j] = 1` 的次数。当我们处理新的一行时，对于每一对 `new_row[i] = new_row[j] = 1`，我们添加 `count[i, j]` 到答案中，然后  `count[i, j]++`。

```Python [ ]
class Solution(object):
    def countCornerRectangles(self, grid):
        count = collections.Counter()
        ans = 0
        for row in grid:
            for c1, v1 in enumerate(row):
                if v1:
                    for c2 in xrange(c1+1, len(row)):
                        if row[c2]:
                            ans += count[c1, c2]
                            count[c1, c2] += 1
        return ans
```

```Java [ ]
class Solution {
    public int countCornerRectangles(int[][] grid) {
        Map<Integer, Integer> count = new HashMap();
        int ans = 0;
        for (int[] row: grid) {
            for (int c1 = 0; c1 < row.length; ++c1) if (row[c1] == 1) {
                for (int c2 = c1+1; c2 < row.length; ++c2) if (row[c2] == 1) {
                    int pos = c1 * 200 + c2;
                    int c = count.getOrDefault(pos, 0);
                    ans += c;
                    count.put(pos, c+1);
                }
            }
        }
        return ans;
    }
}
```


**复杂度分析**

* 时间复杂度：$O(R*C^2)$。其中 $R, C$ 指的是行和列。
* 空间复杂度：使用了 $O(C^2)$ 的额外空间。


####  方法二：
**算法：**
- 我们能改进方法 1 中的方法吗？当一行有 $X$ 个 1 时，我们需要 $O(X^2)$ 的时间来枚举每对 1。当 $X$ 很小时，这是可以接受的；但当 $X$ 很大时，这是较为耗时的操作。
- 假设第一行的元素都是 1 时，`f` 指的是下一行和第一行所匹配 1 的数量。所能够构造角矩形的数量就是所匹配 1 的数量的对数，即 `f * (f-1) / 2`。我们可以使用一个集合和对每行进行简单线性扫描快速找到每个 `f`。

```Python [ ]
class Solution(object):
    def countCornerRectangles(self, grid):
        rows = [[c for c, val in enumerate(row) if val]
                for row in grid]
        N = sum(len(row) for row in grid)
        SQRTN = int(N**.5)

        ans = 0
        count = collections.Counter()
        for r, row in enumerate(rows):
            if len(row) >= SQRTN:
                target = set(row)
                for r2, row2 in enumerate(rows):
                    if r2 <= r and len(row2) >= SQRTN:
                        continue
                    found = sum(1 for c2 in row2 if c2 in target)
                    ans += found * (found - 1) / 2
            else:
                for pair in itertools.combinations(row, 2):
                    ans += count[pair]
                    count[pair] += 1

        return ans
```

```Java [ ]
class Solution {
    public int countCornerRectangles(int[][] grid) {
        List<List<Integer>> rows = new ArrayList();
        int N = 0;
        for (int r = 0; r < grid.length; ++r) {
            rows.add(new ArrayList());
            for (int c = 0; c < grid[r].length; ++c)
                if (grid[r][c] == 1) {
                    rows.get(r).add(c);
                    N++;
                }
        }

        int sqrtN = (int) Math.sqrt(N);
        int ans = 0;
        Map<Integer, Integer> count = new HashMap();

        for (int r = 0; r < grid.length; ++r) {
            if (rows.get(r).size() >= sqrtN) {
                Set<Integer> target = new HashSet(rows.get(r));

                for (int r2 = 0; r2 < grid.length; ++r2) {
                    if (r2 <= r && rows.get(r2).size() >= sqrtN)
                        continue;
                    int found = 0;
                    for (int c2: rows.get(r2))
                        if (target.contains(c2))
                            found++;
                    ans += found * (found - 1) / 2;
                }
            } else {
                for (int i1 = 0; i1 < rows.get(r).size(); ++i1) {
                    int c1 = rows.get(r).get(i1);
                    for (int i2 = i1 + 1; i2 < rows.get(r).size(); ++i2) {
                        int c2 = rows.get(r).get(i2);
                        int ct = count.getOrDefault(200*c1 + c2, 0);
                        ans += ct;
                        count.put(200*c1 + c2, ct + 1);
                    }
                }
            }
        }
        return ans;
    }
}
```

 
**复杂度分析**

* 时间复杂度：$O(N \sqrt N + R*C)$。其中 $N$ 是网格中的个数。
* 空间复杂度：$O(N + R + C^2)$，`rows`, `target` 和 `count` 所使用的空间。
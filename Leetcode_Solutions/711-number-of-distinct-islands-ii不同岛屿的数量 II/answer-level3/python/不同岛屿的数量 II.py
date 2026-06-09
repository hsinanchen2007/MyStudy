#### 方法一：规范化哈希

这道题是「[不同岛屿的数量](https://leetcode-cn.com/problems/number-of-distinct-islands/)」的加强版，不同的是这道题规定两个岛屿通过平移，旋转和翻转能够重合，它们的形状就相同。

我们首先找出每个岛屿，随后将它进行旋转和翻转的操作得到 8 种不同的情况，并对这些情况分别进行哈希。具体来说，对于每一种情况，我们需要计算出岛屿上每个点的局部坐标值。局部坐标值的计算方法是，对于坐标的每一维，求出岛屿上所有点中的最小值，并把所有点的这一维减去这个最小值。形象地来说，就是用一个最小的矩形框住岛屿，矩形的左上角坐标为 (0, 0)，岛屿上每个点的局部坐标值就是相对于矩形左上角的坐标值。

计算出局部坐标值之后，对于每种情况，我们把坐标值放入列表中并进行排序，这样两个仅经过平移能重合的岛屿就可以得到相同的列表。在这 8 种情况中，我们选择最大的那个列表（比较两个列表的大小有很多种方法，由于这个列表中存储的是二维坐标，可以将二维坐标转化为一维坐标，或者直接将二维坐标转化为字符串；两个列表可以用类似字符串比较大小的方法，逐项比较大小），这样两个经过平移，旋转和翻转能够重合的岛屿就可以得到相同的列表。此时就对岛屿完成了规范化哈希。

模拟岛屿的旋转和翻转有很多种方法，在 Python 代码中，我们把坐标看成复数，每次将坐标乘以单位虚数 `1j` 就是一次旋转操作。对于翻转操作，将坐标的实部和虚部交换即可。在 Java 代码中，我们直接进行旋转和翻转操作，对于坐标 $(x, y)$，它的 8 种情况分别为 $(x, y), (-x, y), (x, -y), (-x, -y), (y, x), (-y, x), (y, -x), (-y, -x)$。

```Python [sol1]
class Solution(object):
    def numDistinctIslands2(self, grid):
        seen = set()
        def explore(r, c):
            if (0 <= r < len(grid) and 0 <= c < len(grid[0]) and
                    grid[r][c] and (r, c) not in seen):
                seen.add((r, c))
                shape.add(complex(r, c))
                explore(r+1, c)
                explore(r-1, c)
                explore(r, c+1)
                explore(r, c-1)

        def canonical(shape):
            def translate(shape):
                w = complex(min(z.real for z in shape),
                            min(z.imag for z in shape))
                return sorted(str(z-w) for z in shape)

            ans = None
            for k in xrange(4):
                ans = max(ans, translate([z * (1j)**k for z in shape]))
                ans = max(ans,  translate([complex(z.imag, z.real) * (1j)**k
                                           for z in shape]))
            return tuple(ans)

        shapes = set()
        for r in range(len(grid)):
            for c in range(len(grid[0])):
                shape = set()
                explore(r, c)
                if shape:
                    shapes.add(canonical(shape))

        return len(shapes)
```

```Java [sol1]
class Solution {
    int[][] grid;
    boolean[][] seen;
    ArrayList<Integer> shape;

    public void explore(int r, int c) {
        if (0 <= r && r < grid.length && 0 <= c && c < grid[0].length &&
                grid[r][c] == 1 && !seen[r][c]) {
            seen[r][c] = true;
            shape.add(r * grid[0].length + c);
            explore(r+1, c);
            explore(r-1, c);
            explore(r, c+1);
            explore(r, c-1);
        }
    }

    public String canonical(ArrayList<Integer> shape) {
        String ans = "";
        int lift = grid.length + grid[0].length;
        int[] out = new int[shape.size()];
        int[] xs = new int[shape.size()];
        int[] ys = new int[shape.size()];

        for (int c = 0; c < 8; ++c) {
            int t = 0;
            for (int z: shape) {
                int x = z / grid[0].length;
                int y = z % grid[0].length;
                //x y, x -y, -x y, -x -y
                //y x, y -x, -y x, -y -x
                xs[t] = c<=1 ? x : c<=3 ? -x : c<=5 ? y : -y;
                ys[t++] = c<=3 ? (c%2==0 ? y : -y) : (c%2==0 ? x : -x);
            }

            int mx = xs[0], my = ys[0];
            for (int x: xs) mx = Math.min(mx, x);
            for (int y: ys) my = Math.min(my, y);

            for (int j = 0; j < shape.size(); ++j) {
                out[j] = (xs[j] - mx) * lift + (ys[j] - my);
            }
            Arrays.sort(out);
            String candidate = Arrays.toString(out);
            if (ans.compareTo(candidate) < 0) ans = candidate;
        }
        return ans;
    }

    public int numDistinctIslands2(int[][] grid) {
        this.grid = grid;
        seen = new boolean[grid.length][grid[0].length];
        Set shapes = new HashSet<String>();

        for (int r = 0; r < grid.length; ++r) {
            for (int c = 0; c < grid[0].length; ++c) {
                shape = new ArrayList();
                explore(r, c);
                if (!shape.isEmpty()) {
                    shapes.add(canonical(shape));
                }
            }
        }

        return shapes.size();
    }
}
```

**复杂度分析**

* 时间复杂度：$O(mn \log(mn))$，其中 $m$ 和 $n$ 分别为网格的长和宽。网格中的每个点我们只会遍历一次，由于需要进行排序，因此时间复杂度中有 $\log(mn)$ 这项。
* 空间复杂度：$O(mn)$。
### 解题思路
1. 遍历每一个坐标，累计有多少个立方体 m。
2. 计算一共有多少个贴上的立方体 n，包括：
3. 与右边、下边的邻居有多少个相邻立方体 。
4. 以及每个单元格上，纵轴z上有多少个贴上的立方体。
5. 每一个相邻立方体，需要减去2个重合表面。
6. 即：表面积 = 6*m - 2*n

### 代码

```csharp
public class Solution {
    public int SurfaceArea(int[][] grid) {
            if (grid == null || grid.GetLength(0) == 0 || grid[0].Length == 0)
                return 0;

            // 遍历每一个坐标，累计有多少个立方体 m。
            // 计算一共有多少个贴上的立方体 n，包括：
            // 与右边、下边的邻居有多少个相邻立方体 。
            // 以及每个单元格上，纵轴z上有多少个贴上的立方体。
            // 每一个相邻立方体，需要减去2个重合表面。
            // 即：表面积 = 6*m - 2*n

            int x = grid.GetLength(0);
            int y = grid[0].Length;
            int m = 0;
            int n = 0;

            for (int i = 0; i < y; i++)
            {
                for (int j = 0; j < x; j++)
                {
                    m += grid[i][j];
                    if (i + 1 < grid[0].Length) //x轴上，有多少个和右边贴上的立方体
                    {
                        n += Math.Min(grid[i][j], grid[i + 1][j]);
                    }
                    if (j + 1 < grid[i].Length) //y轴上，有多少个和右边贴上的立方体
                    {
                        n += Math.Min(grid[i][j], grid[i][j + 1]);
                    }
                    if(grid[i][j] >1) //z轴上，有多少个贴上的立方体
                    {
                        n += grid[i][j] -1;
                    }
                }
            }
            return 6 * m - 2 * n;
    }
}
```

## 测试
```csharp
    [TestClass]
    public class SolutionTest
    {
        [TestMethod]
        public void null_grid_should_return_0()
        {
            var sut = new Solution();
            var actual = sut.SurfaceArea(null);
            Assert.AreEqual(0, actual);
        }

        [TestMethod]
        public void empty_grid_should_return_0()
        {
            var sut = new Solution();
            var actual = sut.SurfaceArea(new int[][] { });
            Assert.AreEqual(0, actual);
        }

        [TestMethod]
        public void grid_1_by_1_cubes_2_should_return_2()
        {
            var grid = new int[][] { new int[] { 2 } };

            var sut = new Solution();
            var actual = sut.SurfaceArea(grid);
            Assert.AreEqual(10, actual);
        }

        [TestMethod]
        public void grid_2_by_2_cubes_10_should_return_34()
        {
            var grid = new int[][] { new int[] { 1, 2 }, new int[] { 3, 4 } };

            var sut = new Solution();
            var actual = sut.SurfaceArea(grid);
            Assert.AreEqual(34, actual);
        }

        [TestMethod]
        public void TestMethod3()
        {
            var grid = new int[][] { new int[] { 1, 0 }, new int[] { 0, 2 } };

            var sut = new Solution();
            var actual = sut.SurfaceArea(grid);
            Assert.AreEqual(16, actual);
        }

        [TestMethod]
        public void TestMethod4()
        {
            var grid = new int[][] { new int[] { 1, 1, 1 }, new int[] { 1, 0, 1 }, new int[] { 1, 1, 1 } };

            var sut = new Solution();
            var actual = sut.SurfaceArea(grid);
            Assert.AreEqual(32, actual);
        }

        [TestMethod]
        public void TestMethod5()
        {
            var grid = new int[][] { new int[] { 2, 2, 2 }, new int[] { 2, 1, 2 }, new int[] { 2, 2, 2 } };

            var sut = new Solution();
            var actual = sut.SurfaceArea(grid);
            Assert.AreEqual(46, actual);
        }
    }
```
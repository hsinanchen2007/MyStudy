### 解题思路

##### 1. 题目概述：检查网格中是否存在有效路径

##### 2. 思路：
   - 特征：给了网格,其实整个地图就给出来了;从左上角出发,按照地图走,能否走到右下角决定了解;
   - 方案：整个过程是个递归;到了每个格子,思考的都是,我从哪里来,可以去到哪里;从那个地方来,是否满足要求;满足要求以后自己所在的位置是不是目标位置呢,不是的话,那就递归的进入下一个环节;最上角的格子,不知道是什么类型,索性就假设从 4 个方向来到了 左上角,只要 1 个满足条件了,那么就说明是可行的;
   - 结果：按照地图走,是否能走到右下角

##### 3. 知识点：递归

##### 4. 复杂度分析: 
   - 时间复杂度：O(n*m)
   - 空间复杂度：O(n*m)


### 代码

```csharp []
public class Solution {
        public bool HasValidPath(int[][] grid)
        {
            return
                Recursive(grid, 0, -1, 0, 0) ||
                Recursive(grid, -1, 0, 0, 0) ||
                Recursive(grid, 0, 1, 0, 0) ||
                Recursive(grid, 1, 0, 0, 0);
        }

        private int[][] GetPos(int t, int r, int c)
        {
            var res = new int[2][];
            switch (t)
            {
                case 1:
                    res[0] = new[] { r, c - 1 };
                    res[1] = new[] { r, c + 1 };
                    break;

                case 2:
                    res[0] = new[] { r - 1, c };
                    res[1] = new[] { r + 1, c };
                    break;

                case 3:
                    res[0] = new[] { r, c - 1 };
                    res[1] = new[] { r + 1, c };
                    break;

                case 4:
                    res[0] = new[] { r, c + 1 };
                    res[1] = new[] { r + 1, c };
                    break;

                case 5:
                    res[0] = new[] { r, c - 1 };
                    res[1] = new[] { r - 1, c };
                    break;

                case 6:
                    res[0] = new[] { r - 1, c };
                    res[1] = new[] { r, c + 1 };
                    break;
            }

            return res;
        }

        private int[] FromTo(int[][] list, int fromR, int fromC)
        {
            var one = list[0];
            var two = list[1];

            if (one[0] == fromR && one[1] == fromC)
                return two;

            if (two[0] == fromR && two[1] == fromC)
                return one;

            return null;
        }

        private bool Recursive(int[][] grid, int fromR, int fromC, int toR, int toC)
        {
            var r = grid.Length;
            var c = grid[0].Length;
            if (toR < 0 || toR >= r || toC < 0 || toC >= c) return false;

            var t = grid[toR][toC];
            var list = GetPos(t, toR, toC);
            var re = FromTo(list, fromR, fromC);
            if (re == null) return false;

            if (toR == r - 1 && toC == c - 1) return true;

            return Recursive(grid, toR, toC, re[0], re[1]);
        }
}
```
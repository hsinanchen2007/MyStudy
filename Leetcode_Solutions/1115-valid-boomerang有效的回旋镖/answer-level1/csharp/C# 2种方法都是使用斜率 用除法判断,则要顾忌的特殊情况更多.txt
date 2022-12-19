```C# []
        public bool IsBoomerang(int[][] points)
        {
            return 1.0 * (points[1][0] - points[0][0]) * (points[2][1] - points[1][1]) !=
                1.0 * (points[1][1] - points[0][1]) * (points[2][0] - points[1][0]);
        }

        public bool IsBoomerang(int[][] points)
        {
            /*
             * 题目概述：有效的回旋镖
             * 
             * 思路：
             *  1.是一个数学问题,只要 3 个点不在一条直线上,那么就是满足要求的
             *  2.判断 3 个点是否在一条直线上,这里使用了"斜率",即连续的 2 个点垂直和水平距离的比不相同,则斜率不同,则不在同一条直线上
             *  3.需要特殊处理的地方有 2 个
             *      3.1 3 个点可能重合,所以要做出判断
             *      3.2 当 3 个点位于同一个水平面时,编程语言中的除法会存在问题
             *
             * 知识点：数学
             *
             * 时间复杂度：O(1)
             * 空间复杂度：O(1)
             */

            var pointSet = new HashSet<string>();
            foreach (var pointItem in points)
                pointSet.Add($"{pointItem[0]}_{pointItem[1]}");
            if (pointSet.Count < 3) return false;

            if (points[1][1] - points[0][1] == 0 && points[2][1] - points[1][1] == 0) return false;

            var zeroOneSide = 1.0 * (points[1][0] - points[0][0]) / (points[1][1] - points[0][1]);
            var oneTwoSide = 1.0 * (points[2][0] - points[1][0]) / (points[2][1] - points[1][1]);
            return zeroOneSide != oneTwoSide;
        }
```

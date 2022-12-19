```C# []
        public int[][] AllCellsDistOrder(int R, int C, int r0, int c0)
        {
            /*
             * 题目概述：距离顺序排列矩阵单元格
             * 
             * 思路：
             *  1.遍历出所有的矩阵单元格,然后按照与给定点的曼哈顿距离从小到大排序即可
             *  2.此题使用了 有序列表 的方案,键的值就是曼哈顿距离
             *
             * 知识点：有序列表 数组
             *
             * 时间复杂度：O(nlogn)
             * 空间复杂度：O(n)
             */

            var orderPointsList = new SortedList<int, List<int[]>>();
            for (var r = 0; r < R; r++)
            {
                for (var c = 0; c < C; c++)
                {
                    var key = Math.Abs(r - r0) + Math.Abs(c - c0);
                    if (!orderPointsList.ContainsKey(key))
                        orderPointsList[key] = new List<int[]>();

                    orderPointsList[key].Add(new int[] { r, c });
                }
            }

            var forReturn = new List<int[]>(R * C);
            foreach (var pointItem in orderPointsList)
                forReturn.AddRange(pointItem.Value);

            return forReturn.ToArray();
        }

        public int[][] AllCellsDistOrder(int R, int C, int r0, int c0)
        {
            /*
             * 题目概述：距离顺序排列矩阵单元格
             * 
             * 思路：
             *  1.以给定的单元格为圆心不断向外扩展输出的过程
             *  2.曼哈顿距离也可以看做是移动的距离,上下左右移动是 1 个单元格,斜上斜下移动是 2 个单元格,从移动效率上来看,那就只使用上下左右的方式移动就可以了
             *  3.这个处理过程与 BFS 的核心处理思想是一致的,因此考虑此种算法
             *  4.向外扩展或者说是 BFS 的过程中要注意:不要出界 访问过的距离,就不要再访问了
             *
             * 知识点：BFS 数组 队列
             *
             * 时间复杂度：O(R * C)
             * 空间复杂度：O(R * C)
             */

            var forReturn = new List<int[]>(R * C);

            var queueTemp = new Queue<int[]>();
            var visited = new bool[R, C];
            visited[r0, c0] = true;
            queueTemp.Enqueue(new int[] { r0, c0 });

            var loopRowArray = new int[] { -1, 1, 0, 0 };
            var loopColArray = new int[] { 0, 0, -1, 1 };

            while (queueTemp.Any())
            {
                var curPoint = queueTemp.Dequeue();
                forReturn.Add(curPoint);

                for (var i = 0; i < 4; i++)
                {
                    var newRow = curPoint[0] + loopRowArray[i];
                    var newCol = curPoint[1] + loopColArray[i];

                    if (newRow >= 0 && newRow < R && newCol >= 0 && newCol < C)
                    {
                        if (visited[newRow, newCol]) continue;

                        visited[newRow, newCol] = true;
                        queueTemp.Enqueue(new int[] { newRow, newCol });
                    }
                }
            }

            return forReturn.ToArray();
        }
```

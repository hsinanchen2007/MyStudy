```C# []
        public int[] NumMovesStones(int a, int b, int c)
        {
            /*
             * 题目概述：移动石子直到连续
             * 
             * 思路：
             *  1.每次选择位于边上的石子,然后往中间位置移动
             *  2.这个过程可以看做是一个收缩的过程,中间的位置,是可放置的地方
             *  3.把 3 个石子分别称作"左""中""右"
             *  4."中左"中间空白位置数是 A,"中右"中间空白位置数是 B,那么
             *  5.最小值比较特殊,只可能出现 3 种值 0 1 2
             *      5.1 A 和 B 都有空白位置
             *          5.1.1 有 1 个空白位置是 1,那么是 1;
             *          5.1.2 其它情况,那么是 2;
             *      5.2 A 和 B 有一个无空白位置,有一个有空白位置,那么是 1
             *      5.3 A 和 B 都没有空白位置了,那么是 0;
             *  6.最大值比较好计算了 A + B 即可
             *
             * 知识点：数学
             *
             * 时间复杂度：O(1)
             * 空间复杂度：O(1)
             */

            var intArray = new int[] { a, b, c };
            Array.Sort(intArray);

            var leftSideCount = intArray[1] - intArray[0] - 1;
            var rightSideCount = intArray[2] - intArray[1] - 1;

            var max = leftSideCount + rightSideCount;

            var min = 0;
            if (leftSideCount != 0 || rightSideCount != 0)
            {
                if (leftSideCount > 1 && rightSideCount > 1)
                    min = 2;
                else
                    min = 1;
            }

            return new int[] { min, max };
        }
```

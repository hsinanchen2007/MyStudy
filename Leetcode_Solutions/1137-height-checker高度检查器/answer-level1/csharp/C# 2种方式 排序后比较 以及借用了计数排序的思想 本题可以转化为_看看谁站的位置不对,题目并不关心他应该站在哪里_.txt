```C# []
        public int HeightChecker(int[] heights)
        {
            /*
             * 题目概述：高度检查,其实就是在检查有多少人站的位置不合理,不合理的人自行调整位置就好了
             * 
             * 思路：
             *  1.高度范围是固定的,那么就可以考虑使用统计的方式,看看各个高度下有多少人
             *  2.大的排序趋势其实就是非递减,也即递增的排序方式,知道总体统计的情况下,就知道了每个高度下的人,应该站在哪个区间范围内了
             *  3.挨个排查给定的数组,看看哪个高度的人站的位置不对,那么就做个计数,而这个计数就是最后需要的结果了
             *
             * 关键点：计数排序 数组 哈希表
             * 此种实现方式,在数据量非常大的情况下会更加的有优势
             *
             * 时间复杂度：O(n)
             * 空间复杂度：O(1)
             */

            var heightArray = new int[101];
            foreach (var heightItem in heights)
                heightArray[heightItem]++;

            var curSum = 0;
            for (var i = 0; i < heightArray.Length; i++)
            {
                curSum += heightArray[i];
                heightArray[i] = curSum;
            }

            var forReturn = 0;
            for (var i = 0; i < heights.Length; i++)
            {
                var curHeight = heights[i];

                if (i >= heightArray[curHeight - 1] && i < heightArray[curHeight]) continue;

                forReturn++;
            }

            return forReturn;
        }

        public int HeightChecker(int[] heights)
        {
            /*
             * 题目概述：高度检查器
             * 
             * 思路：
             *  1.题目要求非递减的排序结果,其实就是升序的结果了
             *  2.题目关注的是那些人被移动了
             *  3.无论如果,结果一定是唯一的,只不过题目抽象出了高度
             *  4.只要比较出排序前后,相同的位置人不同,那么这个位置上的人就是被移动过的了
             *
             * 关键点：排序 数组
             *
             * 时间复杂度：O(nlogn)
             * 空间复杂度：O(n)
             */

            var orderArray = heights.OrderBy(i => i).ToList();

            var forReturn = 0;
            for (var i = 0; i < heights.Length; i++)
                if (heights[i] != orderArray[i])
                    forReturn++;

            return forReturn;
        }
```

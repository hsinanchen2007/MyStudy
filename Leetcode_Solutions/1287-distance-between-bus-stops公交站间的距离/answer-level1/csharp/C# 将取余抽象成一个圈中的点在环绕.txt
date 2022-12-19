```C# []
        public int DistanceBetweenBusStops(int[] distance, int start, int destination)
        {
            /*
             * 题目概述：公交站间的距离
             * 
             * 思路：
             *  1.n 个点构成了一个圆圈
             *  2.圆圈的周长必须要遍历一遍所有的点以后才能知道
             *  3.任意给定两个点,求出它们的一段距离以后,另一段距离也就可以得知了
             *
             * 关键点：
             *  1.取余的过程,就像是在圆上做遍历,之前脑中的取余模型是一个线段,现在修正成了一个圆圈,更加准确了
             *
             * 时间复杂度：O(n)
             * 空间复杂度：O(1)
             */

            var sumDistance = distance.Sum();

            var startToDestinationDistance = 0;
            while (start != destination)
            {
                startToDestinationDistance += distance[start++];
                start %= distance.Length;
            }

            return Math.Min(startToDestinationDistance, sumDistance - startToDestinationDistance);
        }
```

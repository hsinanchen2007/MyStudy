```C# []
        public int[] DistributeCandies(int candies, int num_people)
        {
            /*
             * 题目概述：依次分配糖果
             * 
             * 思路：
             *  1.模拟分糖果的过程
             *  2.糖果的数量会逐渐锐减
             *
             * 关键点：
             *  1.从 1 开始,在对数的时间复杂度内就可以累积到 n,因此模拟发糖果的过程也是可行的
             *
             * 时间复杂度：O(log candies)
             * 空间复杂度：O(num_people)
             */

            var forReturn = new int[num_people];

            var candiesCount = 0;
            while (true)
            {
                for (var i = 0; i < num_people && candies > 0; i++)
                {
                    candiesCount++;

                    if (candiesCount <= candies)
                        candies -= candiesCount;
                    else
                    {
                        candiesCount = candies;
                        candies = 0;
                    }

                    forReturn[i] += candiesCount;
                }

                if (candies == 0) break;
            }

            return forReturn;
        }
```

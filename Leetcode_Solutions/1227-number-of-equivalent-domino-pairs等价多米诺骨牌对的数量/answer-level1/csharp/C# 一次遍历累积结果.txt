```C# []
        public int NumEquivDominoPairs(int[][] dominoes)
        {
            /*
             * 题目概述：等价骨牌对的数量
             * 
             * 思路：
             *  1.等价其实就是说拥有的 2 个数字完全一样
             *  2.依次去检查存量,如果有和自己一样的,那么数目就是可以组成对的数目了
             *  3.可以按照特定规则来生成唯一标识,本题可以考虑将两个数字按照大小顺序排好了作为标识
             *  4.依据存值的范围可知,一共只有 9*9=81 种情况,所以使用了一个二维数组来做记录了
             *
             * 关键点：
             *
             * 时间复杂度：O(n) --> 要把所有的存量数据都过滤一遍
             * 空间复杂度：O(1) --> 用作记录的空间大小是固定的
             */

            var forReturn = 0;
            var numPairDic = new int[10, 10];
            foreach (var deminoesItem in dominoes)
            {
                var zero = deminoesItem[0];
                var one = deminoesItem[1];

                var minNum = Math.Min(zero, one);
                var maxNum = Math.Max(zero, one);

                forReturn += numPairDic[minNum, maxNum];
                numPairDic[minNum, maxNum]++;
            }

            return forReturn;
        }
```

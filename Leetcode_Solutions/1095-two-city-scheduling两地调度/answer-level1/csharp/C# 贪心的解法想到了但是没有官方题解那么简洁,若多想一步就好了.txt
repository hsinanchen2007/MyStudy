```C# []
        public int TwoCitySchedCost(int[][] costs)
        {
            /*
             * 题目概述：两地调度
             * 
             * 思路：
             *  1.同样是贪心的思路,这种方式处理问题更加通用
             *  2.先让所有人去往一个城市,计算出总的费用
             *  3.再从这些人中选择 N 个人去往另一个城市,选择的原则是费用增加最少,费用可正可负,排序后选择最小的 N 个人就可以了
             *  4.把这 N 个人去往另一个城市所产生的额外费用汇总到总费用中即可
             *
             * 知识点：贪心算法
             *
             * 时间复杂度：O(nlogn)
             * 空间复杂度：O(n)
             */

            var forReturn = 0;
            foreach (var costItem in costs)
                forReturn += costItem[1];

            var orderCosts = costs.OrderBy(i => i[0] - i[1]).ToList();
            for (var i = 0; i < orderCosts.Count / 2; i++)
                forReturn += orderCosts[i][0] - orderCosts[i][1];

            return forReturn;
        }

        class CostItem
        {
            public int Sub { get; set; }

            public int ZeroPos { get; set; }

            public int OnePos { get; set; }
        }

        public int TwoCitySchedCost(int[][] costs)
        {
            /*
             * 题目概述：两地调度
             * 
             * 思路：
             *  1.本题涉及最优解,可以考虑贪婪的做法
             *  2.如果不考虑每个地方必须有 N 个人去的话,那必然就是去哪里便宜就去哪里,得到的费用一定是最省的
             *  3.但是这么处理完,会得到 2 种结果,刚好每个城市各有N 个人,则不用处理,反之有一个城市的人多了
             *  4.当城市的人数不平衡的时候,就需要一个城市的人转移到另一个城市了
             *  5.如果两个城市的人交换,那么总的费用就是 2 个人所增加的费用,因此不要两个地方换人,而是单向的从一个地方去往另一个地方
             *  5.即从人数多的城市转移到人数少的城市,转移的原则就是谁转移城市增加的费用少,就转移谁
             *
             * 知识点：贪心算法
             *
             * 时间复杂度：O(nlogn)
             * 空间复杂度：O(n)
             */

            var forReturn = 0;

            var zeroCityItemList = new List<CostItem>(costs.Length);
            var oneCityItemList = new List<CostItem>(costs.Length);
            foreach (var item in costs)
            {
                var tempCostItem = new CostItem()
                {
                    ZeroPos = item[0],
                    OnePos = item[1],
                    Sub = Math.Abs(item[0] - item[1])
                };

                if (item[0] <= item[1])
                    zeroCityItemList.Add(tempCostItem);
                else
                    oneCityItemList.Add(tempCostItem);

                forReturn += Math.Min(item[0], item[1]);
            }

            var moreCityItemList = new List<CostItem>();
            if (zeroCityItemList.Count > costs.Length / 2)
                moreCityItemList = zeroCityItemList;
            else if (oneCityItemList.Count > costs.Length / 2)
                moreCityItemList = oneCityItemList;

            if (moreCityItemList.Any())
            {
                var orderList = moreCityItemList.OrderBy(i => i.Sub).ToList();
                for (var i = 0; i < moreCityItemList.Count - costs.Length / 2; i++)
                    forReturn += orderList[i].Sub;
            }

            return forReturn;
        }
```

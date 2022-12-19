```C# []
        public int MaxNumberOfBalloons(string text)
        {
            /*
             * 题目概述：气球的最大数量
             * 
             * 思路：
             *  1.依赖原材料打造最多目标产品计算过程的模拟
             *  2.显然与木桶的短板理论相吻合
             *  3.分析下,目标产品的单位组成成分
             *  4.再分析下,现有的原材料数量
             *  5.依次计算各个成分所能合成的产品数量,结果中的最小值,就是目标值了
             *
             * 关键点：
             *
             * 时间复杂度：O(n) 要把原材料都解析一遍的
             * 空间复杂度：O(1)
             */

            var targetStr = "balloon";
            var targetAnalyzed = AnalyzedText(targetStr);
            var sourceAnalyzed = AnalyzedText(text);

            var valueList = new List<int>();
            foreach (var targetItem in targetAnalyzed)
            {
                var targetChar = targetItem.Key;

                var value = 0;
                if (sourceAnalyzed.ContainsKey(targetChar))
                    value = sourceAnalyzed[targetChar] / targetItem.Value;

                valueList.Add(value);
            }

            return valueList.Min();
        }

        private IDictionary<char, int> AnalyzedText(string text)
        {
            var forReturn = new Dictionary<char, int>();
            foreach (var textItem in text)
            {
                if (!forReturn.ContainsKey(textItem))
                    forReturn[textItem] = 0;

                forReturn[textItem]++;
            }

            return forReturn;
        }
```

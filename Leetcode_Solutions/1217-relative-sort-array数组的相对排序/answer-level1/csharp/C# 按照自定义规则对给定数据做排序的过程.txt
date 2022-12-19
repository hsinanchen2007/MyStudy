```C# []
        public int[] RelativeSortArray(int[] arr1, int[] arr2)
        {
            /*
             * 题目概述：数组的相对排序
             * 
             * 思路：
             *  1.给定一个待排序数组,即 arr1
             *  2.给定一个特定的数组,这是排序的依据
             *  3.有种桶排序的感觉,而桶的顺序是给定的,而非普适的
             *  4.那么就按照桶来统计各个桶内元素的数量
             *  5.然后再按照桶的先后位置生成目标结果
             *
             * 关键点：
             *
             * 时间复杂度：O(m+n)
             * 空间复杂度：O(m+n)
             */

            var forReturn = new List<int>(arr1.Length + arr2.Length);

            var arr2CountDic = new Dictionary<int, int>();
            foreach (var arr2Item in arr2)
                arr2CountDic[arr2Item] = 0;

            var otherNumArray = new List<int>();
            foreach (var arr1Item in arr1)
            {
                if (!arr2CountDic.ContainsKey(arr1Item))
                {
                    otherNumArray.Add(arr1Item);
                    continue;
                }

                arr2CountDic[arr1Item]++;
            }

            foreach (var arr2Item in arr2)
            {
                var countValue = arr2CountDic[arr2Item];
                forReturn.AddRange(Enumerable.Repeat(arr2Item, countValue));
            }

            forReturn.AddRange(otherNumArray.OrderBy(i => i));

            return forReturn.ToArray();
        }
```

```C# []
        public IList<bool> PrefixesDivBy5(int[] A)
        {
            /*
             * 题目概述：可被 5 整除的二进制前缀
             * 
             * 思路：
             *  1.数组会很长很长
             *  2.每个子数组都要判断,是否能被 5 整除
             *  3.可以在一边延伸子数组,一边整除来缩小数据的规模
             *
             * 知识点：位运算 取余
             *
             * 时间复杂度：O(n)
             * 空间复杂度：O(n)
             */

            var forReturn = new List<bool>(A.Length);
            var sum = 0;
            var constNum = 5;
            foreach(var aItem in A)
            {
                sum <<= 1;
                sum |= aItem;
                sum %= constNum;

                forReturn.Add(sum == 0);
            }

            return forReturn;
        }
```



```C# []
        public int NumPrimeArrangements(int n)
        {
            /*
             * 题目概述：质数排列的个数
             * 
             * 思路：
             *  1.数学排列问题
             *  2.计算一个区间范围内的质数,是有一个高效的方案的,时间复杂度在 O(n)~O(n^2)之间
             *  3.数字范围中,质数的个数知道了,质数的排列总数就知道了
             *  4.同理也知道了非质数排列的总数
             *  5.取两个数的乘积就是结果了
             *
             * 关键点：
             *
             * 时间复杂度：O(n^2)
             * 空间复杂度：O(1)
             */

            var constNum = (int)1e9 + 7;
            var primeCount = GetPrimeCount(n);

            var primeSum = GetPossible(primeCount, constNum, 1);
            var result = GetPossible(n - primeCount, constNum, primeSum);
            return (int)result;
        }

        private long GetPossible(int count, int constNum, long initNum)
        {
            if (count == 0) return 0;

            var forReturn = initNum;
            for (var i = 2; i <= count; i++)
                forReturn = forReturn * i % constNum;

            return forReturn;
        }

        private int GetPrimeCount(int n)
        {
            var nPos = new bool[n + 1];
            nPos[0] = nPos[1] = true;

            for (int i = 2; i <= n; i++)
            {
                if (nPos[i]) continue;

                var numCount = 2;
                var newNum = i * numCount;
                while (newNum <= n)
                {
                    nPos[newNum] = true;
                    numCount++;
                    newNum = i * numCount;
                }
            }

            return nPos.Count(i => i == false);
        }
```

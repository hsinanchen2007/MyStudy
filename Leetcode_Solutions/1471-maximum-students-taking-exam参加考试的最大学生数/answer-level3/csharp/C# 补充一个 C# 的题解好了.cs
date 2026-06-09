```C# []
        public int MaxStudents(char[][] seats)
        {
            /*
             * 题目概述：参加考试的最大学生数
             * 
             * 思路：
             *  1.每一排座位坐的学生会相互影响
             *  2.下一排坐的学生,会被上一排影响,或者说,上一排的学生一定程度上影响了下一排要做的学生
             *  3.动态规划的状态定义为:
             *      3.1 dp[i][j]表示第 i 行座位,学生的分布是 j,此时学生的总数是多少
             *      3.2 dp[i][j] = max(dp[i][j],dp[i-1][k] + count(j))
             *      3.3 那么要求的结果就是 max(dp[m][j])
             *  4.dp 本身值的有效性判断主要包括以下几个方面:
             *      4.1 是否在正确的座位上
             *      4.2 同一行是否落座合理
             *      4.3 与上一行相比,落座是否合理
             *
             * 关键点：
             *
             * 时间复杂度：O(M * 2^2n)
             * 空间复杂度：O(M * 2^n)
             */

            var rows = seats.Length;
            var cols = seats[0].Length;

            var seatArray = new int[rows];
            for (int r = 0; r < seats.Length; r++)
            {
                var seatState = 0;
                for (int c = 0; c < seats[r].Length; c++)
                {
                    if (seats[r][c] != '.') continue;

                    seatState |= 1 << c;
                }

                seatArray[r] = seatState;
            }

            var stateSum = 1 << cols;
            var dp = new int[rows, stateSum];

            for (int r = 0; r < rows; r++)
            {
                for (int i = 0; i < stateSum; i++)
                {
                    var isOk = GetMatchedMaxCount(dp, r, i, seatArray, stateSum);
                    if (!isOk.Item1) continue;

                    var icount = GetOneCount(i);
                    dp[r, i] = Math.Max(dp[r, i], icount + isOk.Item2);
                }
            }

            var forReturn = 0;
            for (int i = 0; i < stateSum; i++)
                forReturn = Math.Max(dp[rows - 1, i], forReturn);

            return forReturn;
        }

        private Tuple<bool, int> GetMatchedMaxCount(int[,] dp, int curRow, int curValue, int[] seatArray, int stateSum)
        {
            var curSeat = seatArray[curRow];

            var rightSeat = curValue & curSeat;
            if (rightSeat != curValue) return Tuple.Create(false, 0);

            var leftMove = curValue << 1;
            if ((leftMove & curValue) != 0) return Tuple.Create(false, 0);

            var rightMove = curValue >> 1;
            if ((rightMove & curValue) != 0) return Tuple.Create(false, 0);

            if (curRow == 0) return Tuple.Create(true, 0);

            var maxTemp = 0;
            for (int i = 0; i < stateSum; i++)
            {
                if (dp[curRow - 1, i] == 0) continue;
                if ((leftMove & i) != 0 || (rightMove & i) != 0) continue;

                maxTemp = Math.Max(maxTemp, dp[curRow - 1, i]);
            }

            return Tuple.Create(true, maxTemp);
        }

        private int GetOneCount(int seatState)
        {
            var forReturn = 0;

            while (seatState != 0)
            {
                forReturn++;
                seatState &= seatState - 1;
            }

            return forReturn;
        }
```

题目比较绕，存的是筹码位置而不是筹码个数，
移动2个位置没有代价，移动1个有代价，
所以先过滤数据，移动完所有0代价的数据，
于是得到一个只剩奇偶位的数组，
然后只需要需要比较奇偶数大小，
是把奇数移动到偶数，还是把偶数移动到奇数
于是得出下列算法




        public int MinCostToMoveChips(int[] chips)
        {
            int odd=0,even=0;
            for (int i=0;i<chips.Length;i++)
            {
                if (chips[i] % 2 == 0)
                    even++;
                else
                    odd++;
            }
           return Math.Min(odd, even);
        }
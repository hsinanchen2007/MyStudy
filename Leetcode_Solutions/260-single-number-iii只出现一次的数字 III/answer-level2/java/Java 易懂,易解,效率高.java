**1.对所有数字异或,一样的数字抵消,出现一次的两个数字异或运算后必定不为0;
2.这个数字和相反数做与运算得到一个二进制位最右边一位为1的数字;
3.mask和数组的每个数字做与运算,等于0的分为一组,等于mask的分为一组,同时也将两个不一样的数字分开;
4.完结。**


        public int[] singleNumber(int[] nums) {
            int xor = 0;
            for (int i : nums)// 一样的抵消,不一样的两个数字异或运算结果必定有一位是1
                xor ^= i;

            int mask = xor & (-xor);

            int[] ans = new int[2];
            for (int i : nums) {
                if ((i & mask) == 0)//== 0、 == mask 两种结果
                    ans[0] ^= i;
                else
                    ans[1] ^= i;
            }

            return ans;
        }
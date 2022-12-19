根据题意得到最后一位数加一或者向前进位
public class Solution
    {
        public static int[] PlusOne(int[] digits)
        {
            digits = Solution.Carry(digits, digits.Length-1);
            return digits;
        }
        /// <summary>
        /// 当前位+1
        /// </summary>
        /// <param name="digits">输入数组</param>
        /// <param name="k">当前位数</param>
        /// <returns>数组</returns>
        public static int[] Carry(int[] num, int k)
        {
            if (num[k] == 9 && k >= 1)
            {
                num[k] = 0;
                return Carry(num, k - 1);
            }
            else if (num[k] != 9)
            {
                num[k]++;
                return num;
            }
            else
            {
                int[] num_new = new int[num.Length + 1];
                num_new[0] = 1;
                for (int i = 1; i < num.Length + 1; i++)
                { num_new[i] = 0; }
                return num_new;
            }
        }
    }
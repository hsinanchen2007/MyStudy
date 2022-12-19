**思路1：** 递归，暴力递归会直接超时，可以将递归过程中算出的值存在Dictionary中。(待进一步优化)
```
public class ClimbStairs_70
    {
        private Dictionary<int, int> dict;

        public int ClimbStairs(int n)
        {
            dict = new Dictionary<int, int>();
            return ClimbStairsCount(0, n);
        }

        private int ClimbStairsCount(int i, int n)
        {
            if (i == n)
            {
                return 1;
            }
            if (i > n)
            {
                return 0;
            }

            int result1;
            int result2;
            if (dict.ContainsKey(i + 1))
            {
                result1 = dict[i + 1];
            }
            else
            {
                result1 = ClimbStairsCount(i + 1, n);
                dict.Add(i+1, result1);
            }
            if (dict.ContainsKey(i + 2))
            {
                result2 = dict[i + 2];
            }
            else
            {
                result2 = ClimbStairsCount(i + 2, n);
                dict.Add(i + 2, result2);
            }
            int result = result1 + result2;

            return result;
        }
    }
```

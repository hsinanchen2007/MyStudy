```C# []
        public string GcdOfStrings(string str1, string str2)
        {
            /*
             * 题目概述：字符串最大公因子
             * 
             * 思路：
             *  1.不得不说,把两个字符串正反拼接然后判断的方法很漂亮,这是个拥有最大公因子的充要条件
             *  2.当满足上面那个充要条件以后,直接求得最大公约数,然后把字字符串提供出来就是要求得的结果
             *  3.这题真的是很 track 了
             *
             * 关键点：公约数 字符串
             *
             * 时间复杂度：O(n)
             * 空间复杂度：O(1)
             */

            if (str1 + str2 != str2 + str1) return "";

            return str1.Substring(0, Gcd(str1.Length, str2.Length));
        }

        private int Gcd(int i1, int i2) => i2 == 0 ? i1 : Gcd(i2, i1 % i2);

        public string GcdOfStrings(string str1, string str2)
        {
            /*
             * 题目概述：字符串最大公因子
             * 
             * 思路：
             *  1.因子可以有很多,但要的是 最大公因子 -> 在这个地方栽跟头了
             *  2.使用统一的整数长度去比较,得到最大公因子 --> 起初各自求得公因子,然后做比较,这导致问题变的复杂,还不如一开始就直接做比较了
             *  3.找到公共的子长度,然后分别去判断是否是公因子,不行的话就减小长度再去判断,首次满足条件的就是结果了
             *
             * 关键点：字符串
             *
             * 时间复杂度：O(n)
             * 空间复杂度：O(n)
             */

            var minLength = Math.Min(str1.Length, str2.Length);
            for (var curLength = minLength; curLength >= 1; curLength--)
            {
                if (str1.Length % curLength != 0 || str2.Length % curLength != 0) continue;

                var str1Temp = str1.Substring(0, curLength);
                var str2Temp = str2.Substring(0, curLength);

                if (str1Temp != str2Temp) continue;

                if (IsOK(str1Temp, str1) && IsOK(str2Temp, str2))
                    return str1Temp;
            }

            return "";
        }

        private bool IsOK(string subStr, string str)
        {
            var newList = new List<string>();
            for (var i = 0; i < str.Length; i += subStr.Length)
                newList.Add(str.Substring(i, subStr.Length));

            return newList.All(i => i == subStr);
        }
```

O(N)的解法很简单，先对26求余数处理一遍shifts数据组避免后面int求和溢出，然后从后往前累加shifts数组值，再次对26求余数，得到的是真正每个字符要移动的次数。
最后遍历字符串，计算出位移结果
```C# []
public string ShiftingLetters(string S, int[] shifts)
        {
            var len = 26;
            int temp = 0;
           
            for (var i = shifts.Length - 1; i >= 0; i--)
            {
                temp += shifts[i]%len;
                shifts[i] = temp % len;
            }
            var sb = new StringBuilder();
            for (var i = 0; i < S.Length; i++)
            {
                var res = 'z' - S[i];
                if (shifts[i] <= res)
                {
                    sb.Append((char)(S[i] + shifts[i]));
                }
                else
                {
                    sb.Append((char)('a' + (shifts[i] - res - 1)));
                }
            }
            return sb.ToString();

        }
```



**思路：** 将26进制转换成10进制，可以和题目168联系起来看。
```
public int TitleToNumber(string s)
        {
            int result = 0;
            for (int i = 0; i < s.Length; i++)
            {
                result = result + (int)((s[i] - 'A' + 1) * Math.Pow(26, s.Length - i - 1));
            }

            return result;
        }
```

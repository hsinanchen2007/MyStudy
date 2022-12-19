### 解题思路
将 输入的 字符和自己的字典池比较，获取结果。。 
![Snipaste_2019-12-13_10-19-27.png](https://pic.leetcode-cn.com/8136d95575fea0dc1e413f38af05ef3106cdcfa76b29e58290c336c79540ef44-Snipaste_2019-12-13_10-19-27.png)
这是用.net 4.7做的测试。
### 代码

```csharp
public class Solution {
      Dictionary<string, int> dic = new Dictionary<string, int>   {
            { "I",1 },
            {"V",5},
            {"X",10},
            {"L",50},
            {"C",100},
            {"D",500},
            {"M",1000},

            { "IV" , 4},
            { "IX" , 9 },

            { "XL" , 40},
            { "XC" , 90 },

            { "CD" , 400 },
            { "CM" , 900 }
        };
        public int RomanToInt(string s)
        {
            string str = s;
            bool b = true;
            int values = 0;
            while (b)
            {
                if (str.Length > 1 && dic.ContainsKey(str.Substring(0, 2)))
                {
                    int value = dic[str.Substring(0, 2)];
                    values += value;
                    str = str.Remove(0, 2);
                }
                else
                {
                    int value = dic[str.Substring(0, 1)];
                    values += value;
                    str = str.Remove(0, 1);
                }

                if (str.Length == 0)
                    b = false;
            }

            return values;
        }
}
```
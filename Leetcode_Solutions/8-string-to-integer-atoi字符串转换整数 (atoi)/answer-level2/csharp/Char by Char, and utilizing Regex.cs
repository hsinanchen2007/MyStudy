### 解题思路
我一共尝试了两种解题办法：

#### 解题思路一
1. 先检查传入的string以及 trimed 的 string 是不是为空，如果是空的话，直接return 0；
2. 检查 trimed 的 string的第一个 char，看是不是 '+', '-' 或者 数字中的一个，如果不是的话，也直接return 0；
3. 遍历整个 string，在遇到非数字的 char 的时候，从循环中跳出；
4. 直接在 try-catch 中调用`Int32.Parse()`，如果遇到溢出的异常，则根据已记录的该数字的符号，来决定是返回`Int32`的最大值，还是最小值；


##### 代码

```csharp

public class Solution
{
    public int MyAtoi(string str)
    {
        // 执行用时: 88 ms, 在所有 C# 提交中击败了 88.83% 的用户
        // 内存消耗: 25.3 MB, 在所有 C# 提交中击败了 14.81% 的用户

        if (string.IsNullOrEmpty(str) || string.IsNullOrEmpty(str.Trim())) { return 0; }

        str = str.Trim();
        int integerSign = 1;

        char firstChar = str[0];
        if (firstChar != '+' && firstChar != '-' && !char.IsDigit(firstChar))
        {
            return 0;
        }

        string longestIntStr = "";
        if (firstChar == '-')
        {
            integerSign *= -1;
        }
        else if (char.IsDigit(firstChar))
        {
            longestIntStr += firstChar;
        }

        for (int i = 1; i < str.Length; i++)
        {
            if (char.IsDigit(str[i]))
            {
                longestIntStr += str[i];
            }
            else
            {
                break;
            }
        }

        int parsedInt = 0;
        if (longestIntStr.Length > 0)
        {
            try
            {
                parsedInt = integerSign * Int32.Parse(longestIntStr);
            }
            catch (OverflowException)
            {
                if (integerSign > 0)
                {
                    parsedInt = Int32.MaxValue;
                }
                else
                {
                    parsedInt = Int32.MinValue;
                }
            }
        }

        return parsedInt;
    }
}
```

#### 解题思路二
利用正则表达式（Regex）来从传入的字符串中提取到数字。

P.S 我尝试过摒弃 try-catch，直接写一个C#版本的[这个题解](https://leetcode-cn.com/problems/string-to-integer-atoi/solution/python-1xing-zheng-ze-biao-da-shi-by-knifezhu/) ，可是在提交的时候，遇到了一些巨大无比的test case，比long、decimal还要大。考虑到处理他们的时间与产出不成正比，我最终还是决定使用 try-catch 来处理溢出的异常。

##### 代码

```csharp

using System.Text.RegularExpressions;

public class Solution
{
    public int MyAtoi(string str)
    {
        // 执行用时 : 132 ms, 在所有 C# 提交中击败了 11.44% 的用户
        // 内存消耗 : 28.5 MB, 在所有 C# 提交中击败了 7.41% 的用户
        Regex regex = new Regex(@"^[+|-]?\d+");
        MatchCollection matches = regex.Matches(str.Trim());

        if (matches.Count > 0)
        {
            string matchedString = matches[0].Value;

            try
            {
                return Math.Max(Math.Min(Int32.Parse(matchedString), Int32.MaxValue), Int32.MinValue);
            }
            catch (OverflowException)
            {
                return matchedString[0] == '-' ? Int32.MinValue : Int32.MaxValue;
            }
        };

        return 0;
    }
}
```
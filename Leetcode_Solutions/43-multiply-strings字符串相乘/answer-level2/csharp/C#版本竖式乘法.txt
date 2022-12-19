# 解题思路理解
本题解题采用竖式乘法的解题思路，读取字符串中的每一个字符进行相乘。
例如：`45*45=45*5+45*40=2025`
​
同时本题也考察了对ASCII码表的理解（int与char的对应关系），通过读取字符串每一个字符根据ASCII码的特性转义为具体的数值，字符`0-9`对应的ASCII码值为`48-57`。
例如：字符`5`对应的ASCII码值为`53`，字符`'0'`对应的ASCII码值为`48`，则`int n='5'-'0'=53-48=5`。
​
也可以把具体的数值转换为字符类型
例如：`char c=(char)(5+'0')=5+48=53='5'`，5为int类型的数值，0为字符，ASCII码值`53`对应的字符就是为`5`

下面的代码也是借鉴大神的，通过阅读大神（@empyrealtear）代码也发现自己很多不足之处，还需要多多学习

```C# []
public class Solution {
    public string Multiply(string num1, string num2) {
        StringBuilder sum = new StringBuilder(new string('0', num1.Length + num2.Length));
        for (int i = num1.Length - 1; i >= 0; i--)
        {
            for (int j = num2.Length - 1; j >= 0; j--)
            {
              int next = sum[i + j + 1] - '0' + (num1[i] - '0') * (num2[j] - '0');
              sum[i + j + 1] = (char)(next % 10 + '0');
              sum[i + j] += (char)(next / 10);
            }
        }
        string res = sum.ToString().TrimStart('0');
        return res.Length == 0 ? "0" : res;
    }
}
```


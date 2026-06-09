方法一：枚举
```csharp
public bool IsNumber(string s) {
    if(string.IsNullOrEmpty(s)) return false;
    string str = s.Trim();
    if(string.IsNullOrEmpty(str)) return false;

    int left = 0;
    if(str[left] == '+' || str[left] == '-')
    {
        left++; //跳过开头的正负号
    }

    bool hasDigit = false; //是否有数字
    bool hasE = false; //是否有e
    bool hasDot = false; //是否有小数点
    int len = str.Length;
    for(; left < len; left++)
    {
        if(!char.IsDigit(str[left])) //非数字情况
        {
            if(str[left] == 'e' && !hasE) //还没出现过e
            {
                if(!hasDigit) return false;
                if(left == len - 1) return false; //e在结尾
                if(str[left + 1] == '+' || str[left + 1] == '-')
                {
                    left++; //跳过e后面的正负号
                    if(left == len - 1) return false; //e后面没有数字
                }
                hasE = true;
            }
            else if(str[left] == '.' && !hasDot) //还没出现过小数点
            {
                if(hasE) return false; //e后面出现了小数点
                hasDot = true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            hasDigit = true;
        }
    }
    return hasDigit;
}
```

方法二：正则表达式（比枚举慢，有待优化）
```csharp
public bool IsNumber(string s) {
    if(string.IsNullOrEmpty(s)) return false;
    string str = s.Trim();
    if(string.IsNullOrEmpty(str)) return false;

    string[] list = str.Split('e'); //按e将s拆分
    if(list.Length > 2 || list.Length < 1) return false; //list.Length > 2 表示有多个e
    if(string.IsNullOrEmpty(list[0])) return false; //e前面没有字符
    string str2 = list[0].Replace("+", string.Empty)
        .Replace("-", string.Empty)
        .Replace(".", string.Empty);
    if(string.IsNullOrEmpty(str2)) return false; //e前面没有数字
    if(list.Length == 2 && string.IsNullOrEmpty(list[1])) return false; //e后面没有字符
    
    //^      从字符串的第一个字符开始匹配
    //[+-]?  0或1个正负号
    //\d*    0或多个数字
    //[.]?   0或1个小数点
    System.Text.RegularExpressions.Regex headReg = 
        new System.Text.RegularExpressions.Regex(@"^[+-]?\d*[.]?\d*");
    System.Text.RegularExpressions.Regex tailReg = 
        new System.Text.RegularExpressions.Regex(@"^[+-]?\d+");

    string head = headReg.Match(list[0]).Value;

    //head.Length == 0                  完全不匹配
    //head.Length < list[0].Length      部分匹配
    //head.Length == list[0].Length     完全匹配
    if(head.Length < list[0].Length) return false;
    if(list.Length == 2)
    {
        string tail = tailReg.Match(list[1]).Value;
        if(tail.Length < list[1].Length) return false;
    }
    return true;
}
```
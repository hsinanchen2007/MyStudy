整体思路比较简单
转换时超出int存储范围比较缠人
使用try catch的方法处理两端的异常情况
```C#
public int MyAtoi(string str) {
        string intStr = "";//有效数字字符串
        bool positive = true;//数字是否为正
        bool valid = false;//是否过了第一个非空字符
        for (int i = 0; i < str.Length; i++)
        {
            if (!valid)
            {
                if (str[i] == ' ')
                    continue;
                else if (str[i] == '+' || str[i] == '-')
                {
                    valid = true;
                    positive = (str[i] == '-') ? false : true;
                }
                else if (str[i] >= '0' && str[i] <= '9')
                {
                    valid = true;
                    intStr += str[i];
                }
                else
                    return 0;
            }
            else
            {
                if (str[i] >= '0' && str[i] <= '9')
                    intStr += str[i];
                else
                    break;
            }
        }
        if (intStr == "")
            return 0;
        try
        {
            long temp = Convert.ToInt64(intStr);
            if (positive)
            {
                if (temp > int.MaxValue)
                    return int.MaxValue;
                return (int)temp;
            }
            else
            {
                if ((-1L) * temp < int.MinValue)
                    return int.MinValue;
                return (-1) * (int)temp;
            }
        }
        catch(OverflowException)
        {
            return positive ? int.MaxValue : int.MinValue;
        }
    }
```

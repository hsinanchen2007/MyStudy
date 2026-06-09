### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public int MyAtoi(string str) {
        str = str.Trim();
        long sum = 0;
        int sign = 1; //符号位，用于判断正负号
        int index = 0; 
        if (string.IsNullOrEmpty(str)) return 0;
        if (str[0] == '+' || str[0] == '-')
        {
            sign = str[0] == '+' ? 1 : -1;
            index++;
        }
        for (int i = index; i < str.Length; i++)
        {
            if (!char.IsNumber(str[i]))
                break;

            sum = sum * 10 + str[i] - '0';
            if (sum * sign > int.MaxValue) return int.MaxValue;
            if (sum * sign < int.MinValue) return int.MinValue;
        }
        return (int)sum * sign;
    }
}


```
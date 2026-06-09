C# 编译器有问题，这个为什么不行
public class Solution {
    public int MyAtoi(string str) {
        int dig = 0;
        bool isNegative = false;
        try
        {
            for (var i = 0; i < str.Length; i++)
            {
                if (str[i] == ' ')
                {
                    continue;
                }
                if (!isNegative && str[i] == '-')
                {
                    isNegative = true;
                    continue;
                }
                if (str[i] >= '0' && str[i] <= '9')
                {
                    dig = checked(dig > 0 ? 10 * dig : dig);
                    dig += checked(str[i] - '0');
                    continue;
                }
                if (str[i] < '0' || str[i] > '9')
                {
                    return dig * (isNegative ? -1 : 1);
                }
            }
        }
        catch
        {
            dig = isNegative ? int.MinValue : int.MaxValue;
        }
        return dig;
    }
}
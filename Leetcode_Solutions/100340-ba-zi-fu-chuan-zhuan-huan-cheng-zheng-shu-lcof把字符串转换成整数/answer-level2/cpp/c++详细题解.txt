执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :8.6 MB, 在所有 C++ 提交中击败了100.00%的用户
```
class Solution {
public:
    int strToInt(string str) {
        int res = 0;              // 初始化返回值res
        // 定位第一个不为空的字符
        int begin = 0;             
        while (str[begin] == ' ')  
        {
            ++begin;
            if (begin >= str.length())
            {
                return res;
            }
        }
        // 考虑第一个字符为正负号情况，并用zf标记
        bool zf = true;
        if (str[begin] == '+') {++begin;}
        else if (str[begin] == '-') {++begin; zf = false;}
        // 实现基本功能，累计求数字，遇到非数字则直接退出
        for (int i = begin;i < str.length();++i)
        {
            if (str[i] >= '0' && str[i] <= '9')
            {
                int add = str[i] - '0';
                if (res > INT_MAX / 10 || (res == INT_MAX / 10 && add > 7))
                {
                    if (!zf)
                    {
                        return INT_MIN;
                    }
                    return INT_MAX;
                }
                res = res * 10;
                res += str[i] - '0';
            }
            else
            {
                break;
            }
        }
        // 加上符号
        if (!zf)
        {
            res = -res;
        }
        return res;
    }
};
```

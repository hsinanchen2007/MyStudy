### 解题思路
每次计算num*10时需要防止结果溢出。这里分两种情况，正整数的最后一位最大取7，负整数的最后一位最大取8.所以要分开判断。

### 代码

```cpp
/*
防止溢出
可能的输入有：
1. 0  需要与不能有效转换的0区分？
2. 正整数 > 0x7FFFFFF  或者  负整数  <(signed int)0x8000000
需要注意，遍历字符串时：
1. 遇到非数字或+、-号，停止
2. 遇到+、-号后非数字，停止
3. 遇到数字后，遇到其他字符，停止
4. 超过上限返回最大值、超过下限返回最小值
*/
class Solution {
public:
    int myAtoi(string str) {
        long long num = 0;
        bool flag = true;
        size_t i = 0;
        for(; i < str.size(); ++i)
        {
            if(str[i] != ' ')
                break;
        }
        str = str.erase(0,i);
        char start = *str.begin();
        if(start == '+')
            str.erase(0,1);
        if(start == '-')
        {
            flag = false;
            str.erase(0,1);
        }
        for(char c : str)
        {
            if(c>='0' && c <='9')
            {
                //溢出处理对正数和负数分开讨论
                if(flag && ((num>INT_MAX/10) || (num==INT_MAX/10 &&c-'0'>7)))
                {
                   return INT_MAX;
                }
                if(!flag &&((abs(num)>INT_MIN/10*(-1)) || (abs(num)==INT_MIN/10*(-1) &&c-'0'>8)))
                {
                   return INT_MIN;
                }
                num = num * 10 + (c - '0');
            }
            else
                break;
        }
        return flag ? num : (-1)*num;
    }
};
```
### 解题思路
这个题的思路是使用状态机来做，从后往前进行遍历
需要注意的一点是：如果前一个比后一个大，则需要相加，如XI
但是前一个比后一个小，则需要相减，如IV。

### 代码

```cpp
class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        result += roman(s[s.size()-1]);

        for (int i = s.size()-2; i >= 0; i--)
        {
            if (roman(s[i]) >= roman(s[i+1]))
                result += roman(s[i]);
            else
                result -= roman(s[i]);
        }
        
        return result;
    }

    int roman(char c)
    {
        int r = -1;
        switch (c)
        {
            case 'I':
                r = 1;
                break;
            case 'V':
                r = 5;
                break;
            case 'X':
                r = 10;
                break;
            case 'L':
                r = 50;
                break;
            case 'C':
                r = 100;
                break;
            case 'D':
                r = 500;
                break;
            case 'M':
                r = 1000;
                break;
            default: 
                r = EOF;    
        }
        return r;
    }
};

```
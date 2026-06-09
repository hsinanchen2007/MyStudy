### 思路
假设输入的都是合法罗马数字，我们可以利用罗马数字的定义特点从后向前逆向求解，遇到数值递增（如**V**I）则加上它，遇到数值递减（如**I**V）则减去它，最终求得结果。

### 代码

```cpp
class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        result += romanCharToInt(s[s.size()-1]);

        for (int i = s.size()-2; i >= 0; i--)
        {
            if (romanCharToInt(s[i]) >= romanCharToInt(s[i+1]))
                result += romanCharToInt(s[i]);
            else
                result -= romanCharToInt(s[i]);
        }
        
        return result;
    }

    int romanCharToInt(char c)
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
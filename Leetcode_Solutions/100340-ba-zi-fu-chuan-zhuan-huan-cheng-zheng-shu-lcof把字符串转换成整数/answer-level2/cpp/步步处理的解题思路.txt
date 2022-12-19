### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int strToInt(string str) {
        int size = str.size();
        if(size == 0) return 0;
        long int ans = 0;
        int i = 0;
        bool isTrue = true;
        while(str[i] == ' ')
        {
            i++;
        }
        if(str[i] == '+' || str[i] == '-')
        {
            if(str[i] == '-')
            {
                isTrue = false;
            }
            i++;
        }
        while(isnum(str[i]) && i < size)
        {
            ans = ans * 10 + str[i] - '0';
            i++;
            if(ans >= 2147483648)
            {
                return isTrue ? 2147483647 : -2147483648;
            }
        }
        return isTrue ? ans : -ans;
    }

    bool isnum(const char c)
    {
        return c >= '0' && c <= '9';
    }
};
```
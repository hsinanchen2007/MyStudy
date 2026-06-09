### 解题思路
没啥好说的，这里是重点
```
if((num>INT_MAX/10) || (INT_MAX-num*10 < str[i]-'0'))
    return sign?INT_MAX:INT_MIN;
else num=num*10+(str[i]-'0');
```
如果判断上界回越界，那么在计算前缩小上界
ps：(str[i]-'0')这个括号不能少，否则先加str[i]有可能越界


### 代码

```cpp
class Solution {
public:
    int myAtoi(string str) {
        int start,num=0;
        bool sign=true;
        for(start=0;start<str.length();start++)
        {
            if(str[start] == ' ') continue;
            if(str[start]!='+' && str[start]!='-' && (str[start]>'9' || str[start]<'0')) return 0;
            else break;
        }
        if (str[start] == '+') start++;
        else if (str[start] == '-') 
            {
                sign=false;
                start++;
            }
        if(str[start]<'0' || str[start]>'9') return 0;
        for(int i=start;i<str.length();i++)
            if(str[i]>'9' || str[i]<'0') break;
            else
            {
                if((num>INT_MAX/10) || (INT_MAX-num*10 < str[i]-'0'))
                    return sign?INT_MAX:INT_MIN;
                else num=num*10+(str[i]-'0');
            }
        return sign?num:-num;

    }
};
```
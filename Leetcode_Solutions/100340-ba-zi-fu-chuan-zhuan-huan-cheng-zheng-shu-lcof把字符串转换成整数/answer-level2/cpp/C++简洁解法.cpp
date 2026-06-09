### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int strToInt(string str) {
        if(str.size()==0) return 0;
        int i = 0;
        long ans = 0;
        bool negative = false;

        //跳过前面空格，判断正负
        while(str[i]==' ') i++;
        if(str[i]=='-')
        {
            negative = true;
            i++;
        }
        else if(str[i]=='+')
                i++;
        
        //对非空和非+-号的有效数字进行处理
        for(; i<str.size(); i++)
        {
            if(str[i]>='0' && str[i]<='9')  //判断是否为有效数字
            {
                ans = ans*10 + (str[i] - '0');  //***字符相减转换成int
                if(ans > INT_MAX && negative) return INT_MIN;
                if(ans > INT_MAX && !negative) return INT_MAX;
            }
            else        //碰到非有效数字就退出
                break;
        }

        return negative? -ans:ans;
    }
};
```
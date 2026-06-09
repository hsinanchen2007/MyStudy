### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int myAtoi(string str)
    {        
        int len = str.size();
        if(len == 0)
            return 0;
        int i = 0;
        char temp =' ';
        char single = ' ';
        int res = 0;
        while (str[i] == ' ') {
            i++;
        }
        //判断特殊情况；
        if(str[i] == '+' || str[i] == '-')  {
            single = str[i++];
        } else if( !( str[i]>= '0' && str[i] <= '9') ) {
            return 0;
        }
        //把数字部分取出来；
        int bit = 0;
        while( i < len && ( str[i] >= '0' && str[i] <= '9') ) {
            if(res > INT_MAX/10 ||  (res == INT_MAX/10 && (str[i]-'0') > 7 )){
                return (single == '-') ? INT_MIN : INT_MAX;
            }
            res = (str[i]-'0') + (res * 10);
            i++;
        }

        if(i == len || !( str[i] >= '0' && str[i] <= '9') ) {
            if(single == ' ' || single == '+' ) {
                return res;
            } else {
                return (-1)*res;
            }
        }
        return 0;
    }
};
```
### 解题思路
1、如果没有找到非空字符，直接返回0
2、在累加前，判断前值是否大于INT_MAX / 10，或者等于INT_MAX/10时，累加值大于7，说明累加后的数值溢出，返回最大值或最小值。

### 代码

```cpp
class Solution {
public:
int myAtoi(string str) {
    if(str.find_first_not_of(' ') == str.npos)
        return 0;

    str = str.substr(str.find_first_not_of(' '), str.find_last_not_of(' ') + 1);
    int sign = 1;
    if(str[0] == '-')
        sign = -1;
    if(str[0] == '+' || str[0] == '-')
        str = str.substr(1, str.size());
    
    int res = 0;
    for(int i = 0; i < str.size() && isdigit(str[i]); i++){
        int num = str[i] - '0';
        if(res > INT_MAX / 10 || (res == INT_MAX / 10 && num > 7)) //handle overflow
            return sign > 0 ? INT_MAX : INT_MIN;
        res = res * 10 + num;
    }
    
    return res * sign;
}
};
```
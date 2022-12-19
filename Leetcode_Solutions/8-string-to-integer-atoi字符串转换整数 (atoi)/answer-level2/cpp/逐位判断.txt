### 解题思路
读取最长11位数字存入long，判断其是否超出int边界

### 代码

```cpp
class Solution {
public:
    int myAtoi(string str) {
        int i = 0;
        long ans = 0;
        //去开头空格
        while(i < str.length() &&str[i] == ' ') i++;
        if(i == str.length()) return 0;
        //判断符号
        int symbol = (str[i] == '-') ? -1 : 1; 
        if(str[i] == '-' || str[i] == '+') i++;
        //去开头0
        while(i < str.length() && str[i] == '0') i++;
        //读取最多11位数字，因为INT极限为10位
        for(int j = i; j < str.length() && str[j] >= '0' && str[j] <= '9' && j - i < 11; j++)
            ans = ans*10+(str[j]-'0');
        ans *= symbol;
        if(ans >= INT_MAX) return INT_MAX;
        else if( ans <= INT_MIN) return INT_MIN;
        else return ans;
    }
};
```
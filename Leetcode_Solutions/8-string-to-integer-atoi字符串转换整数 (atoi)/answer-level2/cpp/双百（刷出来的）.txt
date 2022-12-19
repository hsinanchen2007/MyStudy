### 解题思路
坑很多 说一下越界的 ascii码太大 结果虽然是不越界 但运算过程中先加后减可能越界 然后报错
还有判断有效数字前的正负号要一起判断。

### 代码

```cpp
class Solution {
public:
    int myAtoi(string str) {
        int index = 0;
        if (str.length()==0) {return 0;}
        while(str[index]==' ')
            index++;

        if(index == str.length()) return 0;
        int sign = 1;
        if(str[index]=='+') index++; 
        else if(str[index]=='-') {sign = -1; index++;}  
        if(str[index]<'0'||str[index]>'9') return 0;
        int res = 0;  
        for (;index < str.length(); index++) {
            char c = str[index];
            if(c == '+'||c == '-') return sign*res;       
            if (c<'0'||c>'9') {return sign*res;}
            if(res>INT_MAX/10||res == INT_MAX/10&&c>'7')
            {
                if(sign == 1) return INT_MAX;
                else return INT_MIN;
            }
             res =  c-'0'+res*10;
        }
        return sign*res;
    }
};
```
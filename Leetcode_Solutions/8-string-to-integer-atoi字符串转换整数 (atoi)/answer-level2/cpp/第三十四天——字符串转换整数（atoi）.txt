### 解题思路
很朴素的思路

### 代码

```cpp
class Solution {
public:
    int myAtoi(string str) {
        int i = 0;
        long res = 0;
        int size = str.size();
        while(i < size && str[i] == ' ') i++;
        if(!((i<size) || (str[i]=='+') || (str[i]=='-') || (str[i]>='0' && str[i]<='9'))) return 0;
        if('+' == str[i]){
            while(i+1 < size){
                if(str[i+1]>='0' && str[i+1]<='9'){
                    res = res*10+str[i+1]-'0';
                    if(res >= INT_MAX) return INT_MAX;
                    i++;
                }
                else return res;
            }
            return res;
        }
        if('-' == str[i]){
            while(i+1 < size){
                if(str[i+1]>='0' && str[i+1]<='9'){
                    res = res*10+str[i+1]-'0';
                    if(-res <= INT_MIN) return INT_MIN;
                    i++;
                }
                else return -res;
            }
            return -res;
        }
        if(str[i] >= '0' && str[i] <= '9'){
            res = str[i]-'0';
            while(i+1 < size){
                if(str[i+1]>='0' && str[i+1]<='9'){
                    res = res*10+str[i+1]-'0';
                    if(res >= INT_MAX) return INT_MAX;
                    i++;
                }
                else return res;
            }
            return res;
        }
        return res;
    }
};
```
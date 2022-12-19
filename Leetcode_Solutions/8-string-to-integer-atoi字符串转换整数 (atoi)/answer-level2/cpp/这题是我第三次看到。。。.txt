### 解题思路
之前每次都被搞得要死，这次居然一遍过，眼泪掉下来
### 代码

```cpp
class Solution {
public:
    int myAtoi(string str) {
        int p = 0;
        while(str[p] == ' '){
            str.erase(p, 1);   
        }
        if(!str.length()) return 0;
        int n = str.length();
        int flag = 0;
        bool is_pos = true;
        long long x = 0;
        for(int i = 0;i < n;i++){
            if(str[i] > '9' || str[i] < '0'){
                if(flag == 1) break;
                if(str[i] != '-'&& str[i] != '+') break;
                if(str[i] == '-') is_pos = false;
            }
            if(str[i] <= '9'  && str[i] >= '0'){
                x = x*10 + str[i] - '0';
                if(x >= INT_MAX && is_pos) return INT_MAX;
                if(x > INT_MAX && !is_pos) return INT_MIN;
            }
            flag = 1;
        }
        if(!is_pos) return -x;
        return x;
    }
};
```
### 解题思路
 这题其实好做的。就按照它的意思来就好了。找到第一个符合要求的开始计算，直到不合符条件为止。
 这里需要注意的是'+'，这个也是符合条件的。当然，这个对于数字没影响,这个+wrong了两次。
 还有一点，就是数字要在找的过程中就需要判断，我写着写着就忘记在里面判断了，也红了两次。

### 代码

```cpp
class Solution {
public:
    int myAtoi(string str) {
        int f = 0;
        int n = str.length();
        if(n == 0)return 0;
        long s = 0;
        int i = 0;
        while(i < n){
            if(str[i] >= '0' && str[i] <= '9' || str[i] == '-' || str[i] == '+')break;
            else if(str[i] == ' ')i++;
            else return 0;
        }
        if(i == n)return 0;
        if(str[i] == '-')f = 1 , i++;
        else if(str[i] == '+')i++;
        while(i < n){
            if(str[i] >= '0' && str[i] <= '9'){
                if(f)s = s * 10 - (str[i] - '0');
                else s = s * 10 + (str[i] - '0');
                if(s > INT_MAX)return INT_MAX;
                if(s < INT_MIN)return INT_MIN;
                i++;
            }
            else break;
        }
        
        return (int)s;
    }
};
```
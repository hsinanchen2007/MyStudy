### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int myAtoi(string str) {
        int ans = 0;
        int i = 0;
        int flag = 1;
        while(str[i] == ' ') i++;
        if(str[i] == '-'){
            flag = -1;
        }
        if(str[i] == '+' || str[i] == '-') i++;
        while(i < str.size() && isdigit(str[i])){
            int r = str[i] - '0'; // 将字符转换成数字
            if(ans > INT_MAX / 10 || (ans == INT_MAX / 10 && r > 7)){
                return flag > 0 ? INT_MAX : INT_MIN;
            }
            ans = ans * 10 + r;
            i++;
        }
        return flag > 0 ? ans : -ans;
        
    }
};

```
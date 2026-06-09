### 解题思路
1. 处理空格：遇到空格就跳过
2. 处理正负号，定一个变量记录正负号
3. 处理数字

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
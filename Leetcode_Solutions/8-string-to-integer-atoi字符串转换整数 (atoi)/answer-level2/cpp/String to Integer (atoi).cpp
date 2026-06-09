### 解题思路
String to Integer (atoi)

### 代码

```cpp
class Solution {
public:
    int myAtoi(string str) {
        int cur = 0, N = str.size();
        int flag = 1, ret = 0;
        while (cur < N && isspace(str[cur])) ++cur;
        if (cur == N) return 0;
        else if (str[cur] == '-') flag = -1;
        else if (isdigit(str[cur])) ret = str[cur] - '0';
        else if (str[cur] != '+') return 0;
        while (++cur < N && isdigit(str[cur])) 
        {
            int t = (str[cur] - '0') * flag;
            if (ret > INT_MAX / 10 || ret == INT_MAX / 10 && t > 7) return INT_MAX;
            if (ret < INT_MIN / 10 || ret == INT_MIN / 10 && t < -8) return INT_MIN;
            ret = ret * 10 + t;
        }
        return ret;
    }
};
```
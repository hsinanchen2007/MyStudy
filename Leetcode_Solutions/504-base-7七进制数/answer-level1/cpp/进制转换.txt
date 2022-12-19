### 解题思路

### 代码

```cpp
class Solution {
public:
    string convertToBase7(int num) {
        string s = "";
        if(num == 0)
        return "0";
        int flag = 0;
        if(num < 0)
        {
            flag = 1;
            num = -num;
        }
        while(num)
        {
            s += to_string(num % 7);
            num /= 7;
        }
        if(flag)
            s += "-";
        reverse(s.begin(), s.end());
        return s;
    }
};
```
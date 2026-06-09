### 解题思路
好蛋疼的题目。最简单的做法就是一步一步地去过滤。
牛逼一点的做法可以用状态机去做。

### 代码

```cpp
class Solution {
public:
    string trim(const string& str)
    {
        string::size_type pos = str.find_first_not_of(' ');
        if (pos == string::npos)
        {
            return str;
        }
        string::size_type pos2 = str.find_last_not_of(' ');
        if (pos2 != string::npos)
        {
            return str.substr(pos, pos2 - pos + 1);
        }
        return str.substr(pos);
    }
    bool isNumber(string s) {
        s = trim(s);
        int i = 0;
        if (s[0] == '+' || s[0] == '-') {
            i++;
        }
        if (i > 1) {
            return false;
        }
        int dotCount = 0;
        int intCount = 0;
        while((s[i] >= '0' && s[i] <= '9') || s[i] == '.') {
            if (s[i] == '.') {
                dotCount++;
            } else {
                intCount++;
            }
            i++;
        }
        if (dotCount > 1) {
            return false;
        }
        if (intCount == 0 && dotCount > 0) {
            return false;
        }
        int eCount = 0;
        while (s[i] == 'e' || s[i] == 'E') {
            eCount++;
            i++;
        }
        if (eCount > 0 && intCount == 0) {
            return false;
        }
        if (eCount > 1) {
            return false;
        } else if (eCount == 1) {
            if (s[i] == '+' || s[i] == '-') {
                i++;
            }
            intCount = 0;
            while(s[i] >= '0' && s[i] <= '9') {
                i++;
                intCount++;
            }
            if (intCount == 0) {
                return false;
            }
        }
        return i == s.size();
    }
};
```
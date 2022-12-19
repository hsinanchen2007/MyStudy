## 思路一：暴力
1. 首先判断两个字符串长度大小，str1保存长字符串，str2保存短字符串；
2. 判断短字符串的每个子字符串是否能同时除尽两个原始字符串，如果能除尽，则保存在结果集中。


### 代码
时间复杂度：O(m * n)
时间复杂度：O(1)
```cpp
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int len1 = str1.size(), len2 = str2.size();
        if (len1 < len2) {
            swap(str1, str2);
        }
        string res;
        for (int i = 1; i <= len2; ++i) {
            string tmp = str2.substr(0, i);
            if (len1 % i != 0 || len2 % i != 0) continue;
            if (helper(str1, tmp) && helper(str2, tmp)) res = tmp;
        }
        return res;
    }

    bool helper(string &s, string &t) {
        int len1 = s.size(), len2 = t.size();
        if (len1 % len2 != 0) return false;
        for (int i = 0; i < len1; i += len2) {
            string tmp = s.substr(i, len2);
            if (tmp != t) return false;
        }
        return true;
    }   
};
```

## 思路二：字符串连接（最优）
如果两个字符串分别与另一个字符串连接后不相等，则不满足条件；否则，以两个字符串长度的最大公约数的子串即为所求。

### 代码
时间复杂度：O(logn)，gcd函数时间复杂度
时间复杂度：O(1)
```c++
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) return "";
        return str1.substr(0, gcd(str1.size(), str2.size()));
    }  
};
```

### 解题思路
求最大公约数即可

### 代码

```cpp
class Solution {
public:
    int gcd(int x, int y) {
        int z = 0;
        while(x%y != 0) {
            z = x%y;
            x = y;
            y = z;
        }
        return y;
    }
    bool check(string s, string sub) {
        int n = s.size()/sub.size();
        string ans = "";
        for(int i = 0; i < n; i++) {
            ans += sub;
        }
        return ans == s;
    }
    string gcdOfStrings(string str1, string str2) {
        int length1 = str1.size();
        int length2 = str2.size();
        int m = gcd(max(length1, length2), min(length1, length2));
        string s = str1.substr(0, m);
        bool res = check(str1, s) && check(str2, s);
        return res ? s : "";
    }
};
```
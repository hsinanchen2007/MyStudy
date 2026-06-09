根据字符个数复原字符串个数的方程
```
class Solution {
public:
    map<string, int> M = {
        {"one", 1},
        {"two", 2},
        {"three", 3},
        {"four", 4},
        {"five", 5},
        {"six", 6},
        {"seven", 7},
        {"eight", 8},
        {"nine", 9},
        {"zero", 0}
    };
    string originalDigits(string s) {
        map<char, int> m;
        for (auto c : s) ++m[c];
        map<int, int> num;
        num[0] = m['z'];
        num[2] = m['w'];
        num[4] = m['u'];
        num[6] = m['x'];
        num[8] = m['g'];
        num[1] = m['o'] - num[0] - num[2] - num[4];
        num[3] = m['r'] - num[0] - num[4];
        num[5] = m['f'] - num[4];
        num[7] = m['s'] - num[6];
        num[9] = m['i'] - num[5] - num[6] - num[8];
        string res;
        for (auto& p : num) {
            res.insert(res.end(), p.second, p.first + '0');
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/d61425ed12583eb916ebd307fd44c4608f51a727562d8e38a6a087ec76b2050c-image.png)

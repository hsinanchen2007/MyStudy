```
class Solution {
public:
    int countSinglePoint(string& s, int i, int j) {
        if (i > j || i < 0 || j >= s.size()) return 0;
        int res = 0;
        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            --i;
            ++j;
            ++res;
        }
        return res;
    }
    int countSubstrings(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); ++i) {
            res += countSinglePoint(s, i, i);
            res += countSinglePoint(s, i, i + 1);
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/701eb23f0d8907b5e7cec9723ac8b7c228c7ddc7f302bdaf5a5c99260f9f51a3-image.png)

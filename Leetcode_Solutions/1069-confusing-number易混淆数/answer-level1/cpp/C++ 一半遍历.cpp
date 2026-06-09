1，首先判断是否字符合法
2，其次判断翻转是否一致
```
class Solution {
public:
    unordered_map<char, char> M = {
        {'1', '1'}, {'0', '0'}, {'8', '8'},
        {'6', '9'}, {'9', '6'}};
    bool confusingNumber(int N) {
        string s = to_string(N);
        int S = s.size();
        bool is_same = true;
        for (int i = 0; i <= S / 2; ++i) {
            if (M.count(s[i]) == 0 || M.count(s[S - 1 - i]) == 0) return false;
            is_same = is_same && (M[s[i]] == s[S - 1 - i]);
        }
        return !is_same;
    }
};
```
![image.png](https://pic.leetcode-cn.com/0d024365c994a1f0e99770698a526a09c7657336116c19cef7a3ccd55a58af2c-image.png)


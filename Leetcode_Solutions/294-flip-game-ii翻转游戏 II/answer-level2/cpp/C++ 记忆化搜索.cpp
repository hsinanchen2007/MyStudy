```
class Solution {
public:
    map<string, bool> memo;
    bool canWin(string s) {
        if (memo.count(s)) return memo[s];
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == '+' && s[i - 1] == '+') {
                string t = s;
                t[i] = t[i - 1] = '-';
                if (!canWin(t)) {
                    memo[s] = true;
                    return true;
                }
            }
        }
        memo[s] = false;
        return memo[s];
    }
};
```

![image.png](https://pic.leetcode-cn.com/af066dec9d2cd6c962452e0a280ee8d5bcfc2505467487191843bd15871c0d98-image.png)

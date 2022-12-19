```C++ []
class Solution {
public:
    string dfs(string senate, int D, int R) {
        if (D < 0 && -D >= senate.size()) return "Radiant";
        if (R < 0 && -R >= senate.size()) return "Dire";
        string s;
        for (auto c : senate) {
            if (c == 'R' && ++R > 0) {
                s += 'R';
                --D;
                R = 0;
            } else if (c == 'D' && ++D > 0) {
                s += 'D';
                --R;
                D = 0;
            }
        }
        return dfs(s, D, R);
    }
    string predictPartyVictory(string senate) {
        return dfs(senate, 0, 0);
    }
};
```

![image.png](https://pic.leetcode-cn.com/bbeafee387d13f755b02d4f101c158beda22544e9c9debcabdb0f711956bfb84-image.png)

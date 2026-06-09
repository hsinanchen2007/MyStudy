### 贪心
每次选择剩余次数最多的字母，当然要排除最后两个字符一样的情况

### 代码

```cpp
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string s = "";
        vector<int> sur{a, b, c};
        while(true) {
            int ban = -1;
            if (s.size() >= 2 && s[s.size()-1] == s[s.size()-2]) {
                ban = s[s.size()-1] - 'a';
            }
            int which = -1;
            for (int i = 0; i < 3; i++) {
                if (sur[i] == 0 || ban == i) {
                    continue;
                } else if (which == -1 || sur[i] > sur[which]) {
                    which = i;
                }
            }
            if (which == -1) break;
            s += ('a' + which);
            sur[which]--;
        }
        return s;
    }
};
```
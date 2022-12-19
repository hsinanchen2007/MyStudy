### 解题思路

### 代码

```cpp
class Solution {
public:
    int romanToInt(string s) {
        if (s.empty())
            return 0;

        map<char, int> table = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int res = 0;
        int last = table[s[0]];
        int cnt = last;

        for (int i = 1; i < s.size(); i++) {
            int ans = table[s[i]];
            if (ans != last) {
                res += ans > last ? -cnt : cnt;
                cnt = 0;
            }
            last = ans;
            cnt += ans;
        }

        res += cnt;
        return res;
    }
};
```
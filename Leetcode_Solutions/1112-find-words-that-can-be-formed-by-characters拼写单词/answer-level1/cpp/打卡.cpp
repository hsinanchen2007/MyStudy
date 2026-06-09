### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int res = 0;
        vector<int> tb(26,0);
        for (auto t : chars) {
            tb[t - 'a'] ++;
        }
        auto tmp = tb;
        for (auto& w : words) {
            tb = tmp;
            int i = 0;
            for (; i < w.size(); i ++) {
                if (tb[w[i] - 'a'] > 0) {
                    tb[w[i] - 'a']--;
                }else {
                    i = 0;
                    break;
                }
            }
            if (i == w.size()) res += i;
        }
        return res;
    }
};
```
### 解题思路
哈希表

### 代码

```cpp
class Solution {
public:
    vector<int> masterMind(string solution, string guess) {
        vector<int> res(2, 0);
        map<char, int> dict_s;
        map<char, int> dict_g;
        for (int i = 0; i < 4; i++) {
            if (solution[i] == guess[i]) {
                res[0]++;
            } else {
                dict_g[guess[i]]++;
                dict_s[solution[i]]++;
            }
        }
        for (auto it : dict_s) {
            if (dict_g.count(it.first)) {
                res[1] += min(dict_g[it.first], dict_s[it.first]);
            }
        }
        return res;
    }
};
```
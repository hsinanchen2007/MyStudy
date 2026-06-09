### 解题思路
遍历，统计 bulls 数目，并使用两个 vector 分别统计secret 和 guess 中每个数字出现的次数；
统计两个 vector 中字符相同的数目，减去 bulls 的数目 即为 cows 的数目。

### 代码

```cpp
class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0, sz = secret.size();
        vector<int> sc(10, 0), gc(10, 0);
        for (int i = 0; i < sz; ++i) {
            if (secret[i] == guess[i]) bulls++;
            sc[secret[i]-'0']++;
            gc[guess[i]-'0']++;
        }
        for (int j = 0; j < 10; j++) {
            if (sc[j] > 0 && gc[j] > 0) cows += min(sc[j], gc[j]);
        }
        cows -= bulls;
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
```
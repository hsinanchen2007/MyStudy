### 解题思路
不能有前导0
枚举所有值，然后比较是不是在范围中，然后，在范围中cnt加一

### 代码

```cpp
class Solution {
public:
    unordered_map<char, char> mp = {
        {'0','0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}
    };
    int cnt = 0;
    string low, high;
    
    bool isBigerOrEqual(string &big, string &small) {
        int nb = big.length();
        int sn = small.length();
        if (nb < sn) return false;
        if (nb > sn) return true;
        return big >= small;
    }
    
    void dfs(int l, int r, string &path) {
        if (l > r) {
            if (isBigerOrEqual(path, low) && isBigerOrEqual(high, path)) cnt++;
            return;
        }
        if (l == r) {
            char num[3] = {'0', '1', '8'};
            for (int i = 0; i < 3; i++) {
                path[l] = num[i];
                if (isBigerOrEqual(path, low) && isBigerOrEqual(high, path)) cnt++;
            }
            return;
        }
        for (auto &kv: mp) {
            if (l == 0 && kv.first == '0') continue;
            path[l] = kv.first;
            path[r] = kv.second;
            dfs(l + 1, r - 1, path);
        }
    }
    
    int strobogrammaticInRange(string low, string high) {
        this->low = low;
        this->high = high;
        for (int i = low.length(); i <= high.length(); i++) {
            string path(i, '.');
            dfs(0, i-1, path);
        }
        return cnt;
    }
};
```
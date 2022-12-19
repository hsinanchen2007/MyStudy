```
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> m;
        for (auto x : answers) {
            ++m[x + 1];
        }
        int res = 0;
        for (auto& p : m) {
            res += max(p.first, (p.second + p.first - 1) / p.first * p.first);
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/649fd4a1fac32f80fd90b5de595faf413533390cce9a794a8d21e69f1d4203a2-image.png)

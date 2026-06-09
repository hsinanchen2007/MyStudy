![image.png](https://pic.leetcode-cn.com/94afba4a673d1ccaf3b8b3fdfc89007df733baead5bbdedfbf5e79d4134ef015-image.png)

有2个就说明是的，检查set的emplace的返回结果。
```
static auto pre =[] { std::ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr;}();
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        set<int> temp;
        for (auto num : A) {
            if (!temp.emplace(num).second) {
                return num;
            }
        }
        return 0;
    }
};
```

时间复杂度：O(N)
空间复杂度：O(N)

状态转移方程：
ans(x) = ans(x') + 1, (x' 是x去除掉最高位的1的值)

```cpp
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num + 1, 0);        
        int cycle = 1;
        int next_cyle = 2;

        for (int i = 1; i <= num; i++) {
            if (i == next_cyle) {
                cycle = next_cyle;
                next_cyle *= 2;
            }
            ans[i] = ans[i - cycle] + 1;
        }
        return std::move(ans);
    }
};
```
### 解题思路
此处撰写解题思路

### 代码

```cpp
const int opt[5] = {0, 1, 6, 8, 9};
const int ropt[5] = {0, 1, 9, 8, 6};
class Solution {
public:
    int confusingNumberII(int N) {
        int ans = 0;
        function<void(long, long, long)> dfs = [N, &ans, &dfs](long num, long level, long reves){
            for (int i = 0; i < 5; i++) {
                long newnum = num + opt[i];
                long newrevers = reves + ropt[i] * level;
                if (newnum > N) {
                    break;
                }
                if (newnum != newrevers) {
                    ans++;
                }
                dfs(newnum * 10, level * 10, newrevers);
            }
        };
        for (int i = 1; i < 5; i++) {
            long num = opt[i];
            if (num > N) {
                break;
            }
            if (num == 6 || num == 9) {
                ans++;
            }
            dfs(num * 10, 10, ropt[i]);
        }
        return ans;
    }
};

```
## 思路
依次求解2~num_people
设 当前求解的是k
相比于求解k - 2时，增加的节点号是k - 1和k
依次将k节点两个一跳依次指向1~(k - 1)，设指定的节点为i
每次i的位置可以将图分割为i - 1和 k - i - 1 个数的两个子图

```cpp
class Solution {
public:
    int numberOfWays(int num_people) {
        constexpr int mod_value = 1000000007;
        static vector<long long> dp(3, 1); // 使用静态变量缓存历次调用求解过的值，减少重复求解
        int origin_size = dp.size();
        int new_size = num_people + 1;
        if (new_size > origin_size) // 当且仅当当前入参未求解过时求解未求解部分
            dp.resize(new_size, 0);
        for (int index = origin_size + 1; index <= num_people; index += 2) {
            for (int i = 1; i < index; i += 2) {
                    dp[index] += (dp[i - 1] * dp[index - i - 1]) % mod_value;
                    dp[index] %= mod_value;
            }
        }
        return dp[num_people];
    }
};
```
### 解题思路

思路：记忆化回溯
1、比较明显的是这题要么用DP要么用回溯来做，回溯呢还必须要找到记忆化的点，不然肯定会超时的
2、可以选择记忆化回溯的点为mem[i]，表示当前剩余金额为i时的最小选择硬币数
3、需要注意的一点，记忆化回溯对于每个值，应该都是结果值或者说最优解，单次回溯的过程的值不要写记忆化数组中，不一定是最优解
4、记忆化回溯模板
```cpp
int dfs(mem)
{
    // 终止条件
    if (xxx) return -1;
    if (xxx) return 0;
    if (mem[xxx] != -1) return mem[xxx];

    // 求解体
    int minval = INT_MAX;
    for () {
        int val = dfs(mem);
        if (val) {
            minval = min(minval, val);
        }
    }

    // 当次记忆化结果更新，回溯
    return mem[xxx] = minval;
}
```

120ms 16.4M
--- wangtao HW-2020/3/8

### 代码

```cpp
bool cmp(const int& a, const int& b) {
    return a > b;
}
/*
class Solution {
public:
    // 超时D
    void dfs(vector<int>& coins, int amount, int cursum, int coinnum, int &minnum)
    {
        if (coinnum > minnum) return;
        if (cursum > amount) return;
        if (cursum == amount) {
            minnum = min(minnum, coinnum);
            return;
        }
        for (int i = 0; i < coins.size(); i++) {
            dfs(coins, amount, cursum + coins[i], coinnum+1, minnum);
        }
    }

    int coinChange(vector<int>& coins, int amount) {
        int ans = INT_MAX;
        sort(coins.begin(), coins.end(), cmp);
        dfs(coins, amount, 0, 0, ans);
        return ans == INT_MAX ? -1 : ans;
    }
};
*/

// 记忆化：mem[i]当前剩余金额为i时的最小选择硬币数
class Solution {
public:
    int dfs(vector<int>& coins, vector<int>& mem, int needamount)
    {
        if (needamount < 0) return -1;
        if (needamount == 0) return 0;
        if (mem[needamount] != INT_MIN) return mem[needamount];

        int mincoinnum = INT_MAX;
        for (int i = 0; i < coins.size(); i++) {
            int cnt = dfs(coins, mem, needamount - coins[i]);
            if (cnt != -1) {
                mincoinnum = min(mincoinnum, cnt);
            }
        }
        mincoinnum = (mincoinnum == INT_MAX ? -1 : mincoinnum + 1);
        return mem[needamount] = mincoinnum;
    }

    int coinChange(vector<int>& coins, int amount) {
        int ans = INT_MAX;
        sort(coins.begin(), coins.end(), cmp);
        vector<int> mem(amount + 1, INT_MIN);

        ans = dfs(coins, mem, amount);
        return ans == INT_MAX ? -1 : ans;
    }
};

```
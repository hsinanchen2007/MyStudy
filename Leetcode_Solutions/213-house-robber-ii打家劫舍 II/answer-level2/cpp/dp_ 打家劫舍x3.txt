## [I](https://leetcode-cn.com/problems/house-robber/)
### 解题思路
`f[i][0]`表示前i个预约，其中第i个预约不接的最大值
`f[i][0]`表示前i个预约，其中第i个预约接的最大值
```
f[i][0] = max(f[i - 1][0], f[i - 1][1]);
f[i][1] = f[i - 1][0] + nums[i - 1];
```


注意到`f[i]`只依赖与前一个状态`f[i-1]`，所以我们可以不用数组，只用两个变量存储前一个状态
### 代码

```cpp
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution
{
public:
    // int f[2005][2];
    int massage(vector<int> &nums)
    {
        int n = nums.size();
        int preRest = 0, preWork = 0;
        int nowRest = 0, nowWork = 0;
        for (int i = 1; i <= n; i++)
        {
            nowRest = max(preRest, preWork);
            nowWork = preRest + nums[i - 1];
            preRest = nowRest;
            preWork = nowWork;
            // f[i][0] = max(f[i - 1][0], f[i - 1][1]);
            // f[i][1] = f[i - 1][0] + nums[i - 1];
        }
        return max(nowRest, nowWork);
        // return max(f[n][0], f[n][1]);
    }
};


```
## [II](https://leetcode-cn.com/problems/house-robber-ii/)
环形：第一个房子和最后一个不能同时取

所以有两种情况：
+ 不取第一个
+ 不取最后一个  

最后取两种情况的最大值即可
```cpp
class Solution
{
public:
    // int f[2005][2];
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
        {
            return 0;
        }
        if (n == 1)
            return nums[0];
        int preRest = 0, preWork = 0;
        int nowRest = 0, nowWork = 0;
        for (int i = 1; i < n; i++)
        {
            nowRest = max(preRest, preWork);
            nowWork = preRest + nums[i - 1];
            preRest = nowRest;
            preWork = nowWork;
        }
        int ans = max(preRest, preWork);
        preRest = 0, preWork = 0;
        for (int i = 2; i < n; i++)
        {
            nowRest = max(preRest, preWork);
            nowWork = preRest + nums[i - 1];
            preRest = nowRest;
            preWork = nowWork;
        }
        nowWork = preRest + nums[n - 1];
        ans = max(ans, nowWork);
        return ans;
    }
};
```

## [III](https://leetcode-cn.com/problems/house-robber-iii/)
树形：孩子和父亲不能同时取

思路是类似的，注意`preWork`不一样，有三种情况：
+ 左右都取
+ 取左不取右
+ 取右不取左
```cpp
class Solution
{
public:
    pair<int, int> dfs(TreeNode *now)
    {
        if (now == NULL)
            return make_pair(0, 0);
        pair<int, int> le = dfs(now->left);
        pair<int, int> ri = dfs(now->right);
        int preRest = le.first + ri.first;
        int preWork = max(le.first + ri.second, max(le.second + ri.first, le.second + ri.second));
        int nowWork = preRest + now->val;
        int nowRest = max(preRest, preWork);
        return make_pair(nowRest, nowWork);
    }
    int rob(TreeNode *root)
    {
        pair<int, int> ans = dfs(root);
        return max(ans.first, ans.second);
    }
};
```
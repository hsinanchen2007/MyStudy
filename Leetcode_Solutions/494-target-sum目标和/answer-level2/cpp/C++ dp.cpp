### 解题思路
参照大佬们的思路写的C++版本。出处
https://leetcode-cn.com/problems/target-sum/solution/python-dfs-xiang-jie-by-jimmy00745/

该题的经典解法就是用dp，设dp[i][j] 表示用数组中的前 i 个元素，组成和为 j 的方案数。那么dp递推关系为
```
dp[i][j] = dp[i - 1][j - nums[i]] + dp[i - 1][j + nums[i]]
```
这里需要处理一下第二个下标为负数的问题，题解是通过加上所有数的和来解决的。

这位大佬是思路比较奇特，先做了些处理，简化了dp关系。
把nums分成两部分，一部分加“+”，一部分加“-”，那么有
```
S = sum(P) - sum(N)
```
对上式两边同时加上nums的和sum，有
```
S + sum = sum(P) - sum(N) + sum // 因为 sum = sum(P) - sum(N)
=>
S + sum = 2 * sum(P)  
=>
sum(P) = (S + sum) / 2
```
这样就将问题转换为了，每个数只能加“+”，求得到和为P的组合数目的问题。
那么上面的dp还是可以用的，只不过递推关系变得简单了
```
dp[i][j] += dp[i - 1][j - nums[i]];
```
初始条件dp[0][0] = 1，表示选0个数的时候，求和为0的方法个数有1种。
然后你发现每次递归只依赖于上一次的结果，所以可以dp压缩一下，变为
```
dp[j] += dp[j - nums[i]];
```
但这个时候要注意递推的顺序，因为我们会改变dp[j]的值，所以只能从大到小进行j遍历。j的范围从P到num[i]，因为j-num[i]要大于等于0.

另外，提交的时候发现使用空间超了，有个用例S=100000000，但是sum才1000不到，所以这里可以再剪枝一下，abs(S) > sum的时候，直接返回0。

然后，贼快
![image.png](https://pic.leetcode-cn.com/26cc36a363873cdb10ae7c72168024965b4097645a1cd541ba5c27aaab184d64-image.png)

### 代码

```cpp
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for (int n : nums) {
            sum += n;
        }
        if (abs(S) > sum ||(sum + S) % 2 == 1) {
            return 0;
        }
        int p = (sum + S) / 2;
        vector<int> dp = vector<int>(p+1, 0);
        dp[0] = 1;
        for (auto n : nums) {
            for (int j=p; j>=n; j--) {
                dp[j] += dp[j-n];
            }
        }
        return dp[p];
    }
};
```
### 解题思路
与该题类似：
435. 无重叠区间
https://leetcode-cn.com/problems/non-overlapping-intervals/

两种算法：
1.贪心
2.动态规划

1.贪心：
1）当前元素pairs[i][0]与上一个元素的右边界end（pairs[j][1]）未发生重叠时，计数+1，更新end边界为pairs[i][1]；
2）当前元素pairs[i][0]与上一个元素的右边界end（pairs[j][1]）发生重叠时，取两者右边界的最小值作为新的右边界。

### 代码

```cpp
class Solution {
public:
    int findLongestChain(vector<vector<int>> &pairs)
    {
        sort(pairs.begin(), pairs.end());
        int count = 0;
        int end = INT32_MIN;

        for (int i = 0; i < pairs.size(); i++) {
            if (pairs[i][0] > end) {
                count++;
                end = pairs[i][1];
            } else {
                end = min(pairs[i][1], end);
            }
        }

        return count;
    }
};
```

2.动态规划
dp[i]表示第i个元素时的最大数对链个数
转移矩阵：
1）dp[i] = dp[j]+1，元素j必须满足j的右边界小于i的左边界，即pairs[j][1]<pairs[i][0]
2）否则，dp[i] =1;

```cpp
class Solution {
public:
    int findLongestChain(vector<vector<int>> &pairs)
    {
        sort(pairs.begin(), pairs.end());
        vector<int> dp = vector<int>(pairs.size(), 1);

        for (int i = 0; i < dp.size();i++){
            for (int j = 0; j < i;j++){
                if(pairs[j][1]<pairs[i][0]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[dp.size() - 1];
    }
};
```

### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        //方法一，动态规划（最长上升子序列思路）
        /*
        sort(pairs.begin(), pairs.end());//这里排序是因为保证以当前数对为结尾的最长数对只会产生在当前数对的左面
        vector<int> dp(pairs.size()+10, 1);//从起点到当前数对的最长上升个数
        int ans = 0;
        for(int i = 1;i < pairs.size();++i){
            for(int j = 0;j < i;++j){ 
                if(pairs[j][1] < pairs[i][0])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
        */
        //方法二，贪心（区间贪心问题）
        //排序为了找到小于当前数对左端点的第一个数
        sort(pairs.begin(), pairs.end(), [](const auto& a, const auto& b){
            return a[1] < b[1];
        });
        int ans = 0;
        int cur = INT_MIN;//cur是当前上升数对的右端点
        for(auto t : pairs){
            if(t[0] > cur){
                ++ans;
                cur = t[1];
            }
        }
        return ans;
    }
};
```
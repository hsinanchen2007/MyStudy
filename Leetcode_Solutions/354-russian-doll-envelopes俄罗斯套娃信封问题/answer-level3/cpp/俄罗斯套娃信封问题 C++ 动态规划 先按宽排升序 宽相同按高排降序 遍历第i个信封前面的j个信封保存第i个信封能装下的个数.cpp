### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    
    // 先按w排序，若w相同，则按h由高到低排序；若w不同，则按w由小到大排序
    static bool cmp(const vector<int> & p1, const vector<int> &p2) {
        return p1[0]<p2[0]||(p1[0]==p2[0]&&p1[1]>p2[1]);
    }
    
    // 动态规划，时间复杂度O(n^2)，空间复杂度O(n)
    int maxEnvelopes1(vector<vector<int>>& envelopes) {
        if (envelopes.empty()) return 0;
        // 先按w排序，若w相同，则按h由高到低排序；若w不同，则按w由小到大排序
        sort(envelopes.begin(),envelopes.end(),[](const vector<int>& a,const vector<int>& b) {
            return a[0]<b[0]||(a[0]==b[0]&&a[1]>b[1]);
        });
        // 信封个数n，结果个数res
        int n = envelopes.size(), res = 0;
        // 动态规划数组dp[i]表示以i为最大的信封最多能连续套进多少个小信封，初始化元素全为1
        vector<int> dp(n,1);
        // 遍历信封
        for (int i=0; i<n; i++) {
            // 遍历第i个信封前面的信封
            for (int j=0; j<i; j++) {
                // 如果第i个信封前面的信封能放进第i个信封，则更新dp[i]
                if (envelopes[j][1]<envelopes[i][1]) {
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
            res = max(res,dp[i]);
        }
        return res;
    }
    
    // 优化：动态规划+二分法，时间复杂度O(nlogn)，空间复杂度O(n)
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.empty()) return 0;
        // 先按w排序，若w相同，则按h由高到低排序；若w不同，则按w由小到大排序
        sort(envelopes.begin(),envelopes.end(),[](const auto& a,const auto& b){
            return a[0]<b[0]||(a[0]==b[0]&&a[1]>b[1]);
        });
        // 动态规划数组dp
        vector<int> dp;
        // 遍历信封
        for (auto& en:envelopes) {
            // 返回一个非递减序列[dp.begin(), dp.end()]中的第一个大于值en[1]的位置。
            int idx = lower_bound(dp.begin(),dp.end(),en[1]) - dp.begin();
            if ( idx>=dp.size() ) {
                dp.emplace_back(en[1]);
            }
            else {
                dp[idx] = en[1];
            }
        }
        return dp.size();
    }
};



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static bool cmp(const vector<int> & p1, const vector<int> &p2) {
    return p1[0]<p2[0]||(p1[0]==p2[0]&&p1[1]>p2[1]);
}

int maxEnvelopes1(vector<vector<int>>& envelopes) {
    if (envelopes.empty()) return 0;
    sort(envelopes.begin(),envelopes.end(),[](const vector<int>& a,const vector<int>& b) {
        return a[0]<b[0]||(a[0]==b[0]&&a[1]>b[1]);
    });
    int n = envelopes.size(), res = 0;
    vector<int> dp(n,1);
    for (int i=0; i<n; i++) {
        for (int j=0; j<i; j++) {
            if (envelopes[j][1]<envelopes[i][1]) {
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
        res = max(res,dp[i]);
    }
    return res;
}

int main() {
    vector<vector<int>> envelopes = {{5,4}, {6,4}, {6,7}, {2,3}};
    cout << maxEnvelopes1(envelopes) << endl;
}



```
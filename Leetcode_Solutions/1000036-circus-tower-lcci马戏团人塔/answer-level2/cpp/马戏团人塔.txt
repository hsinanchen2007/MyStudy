### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int bestSeqAtIndex(vector<int>& height, vector<int>& weight) {
        static auto speedup = [](){ios::sync_with_stdio(false);cin.tie(nullptr);return nullptr;}();
        vector<pair<int, int> > arr;
        vector<int> dp(height.size()+1, 0);
        for (int i = 0; i < height.size(); ++i){
            arr.push_back(make_pair(height[i], weight[i]));
        }
        sort(arr.begin(), arr.end(), [](pair<int,int> &a,pair<int,int> &b){
            if (a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        });

        int res = 1;
        dp[1] = arr.front().second;
        for (int i = 1; i < arr.size(); ++i){
            if (arr[i].second > dp[res]){
                dp[++res] = arr[i].second;
            }
            else{
                auto pos = lower_bound(dp.begin()+1,dp.begin()+res+1,arr[i].second);
                *pos = arr[i].second;
            }
        }
        return res;
    }
};
```
### 解题思路
把两个数据（最长的长度，路径数量）封装到一个pair里，就可以比较方便的进行追踪。

### 代码

```cpp
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<pair<int,int>> ans(nums.size());
        int maxLen = 1;
        ans[0] = pair<int,int>(1,1);
        for (int i=1; i<nums.size(); i++) {
            ans[i].first = 1;
            ans[i].second = 1;
            for (int j=0; j<i; j++) {
                if (nums[j]<nums[i]) {
                    if (ans[j].first+1 > ans[i].first) {
                        ans[i].first = ans[j].first+1;
                        ans[i].second = ans[j].second;
                    }
                    else if (ans[j].first+1 == ans[i].first) {
                        ans[i].second += ans[j].second;
                    }
                }
            }
            maxLen = max(maxLen, ans[i].first);
        }
        int re = 0;
        for (int i=0; i<nums.size(); i++) {
            if (ans[i].first == maxLen) re+=ans[i].second;
        }
        return re;
    }
};
```
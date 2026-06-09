### 解题思路
我爱你
### 代码

```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target)
    {
        vector<vector<int>> ans;
        int rig;
        int sum = 0, cnt = 0;
        for (int i = 1; i <= target / 2; i++)
        {
            int j = i;
            for ( ; sum < target; j++)
                sum += j;
            if (sum == target)
            {
                rig = j;
                ans.push_back({});
                for (int k = i; k < j; k++)
                    ans[cnt].push_back(k);
                cnt++;
            }
            sum = 0;
        }
        return ans;
    }
};
```
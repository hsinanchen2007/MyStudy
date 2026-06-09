### 解题思路


### 代码

```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        if(nums.size() == 0)
        {
            return ans;
        }
        for(int i = 0 ; i < nums.size() - k + 1; i++)
        {
            priority_queue<int> q;
            for(int j = i ; j < i + k ; ++j)
            {
                q.push(nums[j]);
            }
            ans.push_back(q.top());
        }
        return ans;
    }
};
```
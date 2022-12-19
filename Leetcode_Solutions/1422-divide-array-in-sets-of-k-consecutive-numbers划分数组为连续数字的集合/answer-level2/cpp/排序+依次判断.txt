### 解题思路


### 代码

```cpp
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto num : nums)
            mp[num]++;
        sort(nums.begin(), nums.end());
        for(auto num : nums)
        {
            if(mp[num] > 0)
            {
                mp[num]--;
                for(int i = 1 ; i < k ; ++i)
                {
                    if(mp[num + i] != 0)
                        mp[num + i]--;
                    else
                        return false;
                }
            }
        }
        return true;
    }
};
```


### 代码

```cpp
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int>m;
        vector<int> ans;
        if(nums.size() == 0)
        return ans;
        for(int i = 0 ;i < nums.size();i++)
        {
            m[nums[i]]++;
            
        }
        for(auto &it : m)
        {
            if(it.second > nums.size() / 3)
            {
                ans.push_back(it.first);
            }

        }
        return ans;
        
    }
};
```
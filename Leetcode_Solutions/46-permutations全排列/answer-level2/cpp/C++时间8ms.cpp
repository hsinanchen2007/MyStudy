```
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return ret;
        for(int i = 0; i < nums.size(); ++i) {
            mp[nums[i]] = 0;
        }
        permuteCore(nums);
        for(auto it = st.begin(); it != st.end(); ++it) {
            ret.push_back(*it);
        }
        return ret;
        
    }
    void permuteCore(vector<int>& nums) {
        if(temp.size() == nums.size()) {
            st.insert(temp);
            return;
        }
        for(int i = 0; i <nums.size(); ++i) {
            if(mp[nums[i]] == 1) {
                continue;
            }
            else {
                mp[nums[i]] = 1;
                temp.push_back(nums[i]);
                permuteCore(nums);
                mp[nums[i]] = 0;
                temp.pop_back();
            }
        }
        return;
    }
    unordered_map<int, int> mp;
    vector<int> temp;
    set<vector<int>> st;
    vector<vector<int>> ret;
};
```

```
class Solution {
    void backtrack(vector<int> &nums, int i, vector<int> &v, vector<vector<int> > &vs){
        vs.push_back(v);
        for(int j=i; j<nums.size(); ++j){
            v.push_back(nums[j]);
            backtrack(nums,j+1,v,vs);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        vector<vector<int> > vs;
        backtrack(nums,0,v,vs);
        return vs;
    }
};
```

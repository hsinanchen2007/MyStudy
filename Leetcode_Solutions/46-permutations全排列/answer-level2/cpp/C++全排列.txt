总以为哪里有坑，没想到这么顺利
执行用时 : 4 ms, 在所有 C++ 提交中击败了91.29%的用户
内存消耗 : 8.4 MB, 在所有 C++ 提交中击败了100.00%的用户
```
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        do{
            ans.push_back(nums);
        }while(next_permutation(nums.begin(), nums.end()));
        return ans;
    }
};
```

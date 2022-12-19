### 解题思路


### 代码

```cpp
class Solution {
    vector<vector<int>> res;
    vector<int> cur;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i<=nums.size(); i++){
            DFS(nums, 0, i);
        }
        //DFS(nums, 0, nums.size())
        
        return res;
    }
    void DFS(vector<int>& nums, int begin, int k){
        if(cur.size() == k){
            res.push_back(cur);
            return;
        }
        for(int i = begin; i<nums.size(); i++){
            cur.push_back(nums[i]);
            DFS(nums, i+1, k);
            cur.pop_back();
        }
    }
};
```
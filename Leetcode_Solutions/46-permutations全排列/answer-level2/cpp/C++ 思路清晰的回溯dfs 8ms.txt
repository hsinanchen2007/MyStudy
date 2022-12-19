### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
private:
    vector<vector<int>> res;
public:
    void dfs(vector<int>& tmp, vector<bool>& used, vector<int>& nums){
        if(tmp.size()==used.size()){
            res.push_back(tmp);
            return;
        }
        for(int i=0; i<used.size(); i++){
            if(used[i]==false){
                used[i] = true;
                tmp.push_back(nums[i]);
                dfs(tmp,used,nums);
                used[i] = false;
                tmp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        res.clear();
        if(nums.empty()) return res;
        vector<int> tmp;
        vector<bool> used(nums.size(),false);
        dfs(tmp,used,nums);
        return res;
    }
};
```
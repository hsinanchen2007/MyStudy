### 解题思路
回溯法，递归剪枝

### 代码

```cpp
class Solution {
    vector<vector<int>> res;
    vector<int> temp;
    vector<int> occupy;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums);
        return res;
    }
    void dfs(vector<int>& nums){
        if (temp.size()==nums.size()) res.push_back(temp);
        else if (temp.size()<nums.size()) {
            for (int i=0;i<nums.size();i++){
                if (find(occupy.begin(),occupy.end(),i)==occupy.end()){
                    temp.push_back(nums[i]);
                    occupy.push_back(i);
                    dfs(nums);
                    temp.pop_back();
                    occupy.pop_back();
                }
            }
        }
    }
    
};
```
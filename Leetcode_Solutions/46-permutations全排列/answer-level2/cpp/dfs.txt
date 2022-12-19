### 解题思路
最基础dfs思路，没有其他大佬那么精简。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> tmp;
    int len;
    vector<int> nums;

public:
    vector<vector<int>> permute(vector<int>& nums) {
        len = nums.size();
        if(len < 2) {
            ans.push_back(nums);
            return ans;
        }
        
        bool vis[len];
        memset(vis, 0, sizeof(vis));
        this->nums = nums;
        
        dfs(vis);

        return ans;
    }

    void dfs(bool* vis){
        if(tmp.size() == len){
            ans.push_back(tmp);
            return;
        }

        for(int i=0; i<len; i++){
            if(!vis[i]){
                vis[i] = true;
                tmp.push_back(nums[i]);
                dfs(vis);
                vis[i] = false;
                tmp.pop_back();
            }
        }
    }
};
```
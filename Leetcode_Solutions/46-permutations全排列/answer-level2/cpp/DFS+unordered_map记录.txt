### 解题思路
深度优先搜索，不断遍历，每次用map查看当前要使用的数字是否用过了。

执行用时 :4 ms, 在所有 C++ 提交中击败了93.51%的用户
内存消耗 :11.2 MB, 在所有 C++ 提交中击败了6.05%的用户

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> res;
    unordered_map<int,int> mp;
    void dfs(vector<int>& nums,vector<int> tmp,int i){
        if(i==nums.size()) res.push_back(tmp);
        for(auto a:nums){
            if(mp.find(a)!=mp.end()) continue;
            else{
                mp[a]=1;
                tmp.push_back(a);
                dfs(nums,tmp,i+1);
                tmp.pop_back();
                mp.erase(a);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.empty()) return res;
        vector<int> tmp;
        dfs(nums,tmp,0);
        return res;
    }
};
```
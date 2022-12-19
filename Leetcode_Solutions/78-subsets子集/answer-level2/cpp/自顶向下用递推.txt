### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> v;
    vector<int> v1;
    void dfs(vector<int>& nums,int n){
        if(n==0){
            v1.clear();
            v.push_back(v1);
            return;
        }
        dfs(nums,n-1);   //得到nums[0...n-2]所有子集
        int len=v.size();
        for(int i=0;i<len;++i){
            v1=v[i];
            v[i].push_back(nums[n-1]);
            v.push_back(v1);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums,nums.size());
        return v;
    }
};
```
### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> v;
    vector<int> v1;
    vector<bool> hash;
    void dfs(vector<int> &nums,int index){
        v.push_back(v1);
        if(index>=nums.size())
           return;
        for(int i=index;i<nums.size();++i){
          if(hash[i]==false){
            if(i!=0&&hash[i-1]==false&&nums[i]==nums[i-1])                                 continue;
            hash[i]=true;
            v1.push_back(nums[i]);
            dfs(nums,i);
            v1.pop_back();
            hash[i]=false;
            }
        }
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        hash.resize(nums.size());
        sort(nums.begin(),nums.end());
        dfs(nums,0);
        return v;
    }
};
```
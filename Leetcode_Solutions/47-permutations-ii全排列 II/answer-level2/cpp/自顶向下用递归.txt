### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> v;
    vector<int> v1,hashtable;
    void dfs(vector<int>& nums,int index){
          if(index>=nums.size())
          {  
                 v.push_back(v1);
                 return;
          }
          for(int i=0;i<nums.size();++i){
                 if(hashtable[i]==false){
                     if(i!=0&&nums[i]==nums[i-1]&&hashtable[i-1]==false)
                         continue;
                     v1.push_back(nums[i]);
                     hashtable[i]=true;
                     dfs(nums,index+1);
                     hashtable[i]=false;
                     v1.pop_back();
                 }
          }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        hashtable.resize(nums.size());
        sort(nums.begin(),nums.end());
        dfs(nums,0);
        return v;
    }
};
```
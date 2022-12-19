### 解题思路
将nums 存入map 中，然后按照map进行遍历。


### 代码

```cpp
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> path;
        vector<vector<int>> res;
        unordered_map<int,int> m;
        for(int i : nums)
            m[i]++;
        dfs(m,path,res,nums.size());
        return res;
        
    }
    void dfs(unordered_map<int,int>& m, vector<int>& path, vector<vector<int>> &res,int len){
        if(path.size() == len){
            res.push_back(path);
            return;
        }
        unordered_map<int,int>::iterator iter;
        for(iter = m.begin(); iter != m.end(); iter++){
            if( iter->second != 0){
                iter->second--;
               path.push_back(iter->first); 
               dfs(m,path,res,len);
               path.pop_back();
               iter->second++; //将元素个数加回去
            }
  
        }
        
    }
};
```
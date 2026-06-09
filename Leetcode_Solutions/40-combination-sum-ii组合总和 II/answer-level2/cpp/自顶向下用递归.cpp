### 解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> v;
    vector<int> temp;
    int flag;
    void dfs(vector<int>& candidate,int target,int index){
        if(target==0)
         {
            v.push_back(temp);
            return;
         }
         if(index>=candidate.size())
           return;
         if(target<0)
           return;         
         if(index>0&&candidate[index-1]==candidate[index]&&flag==0){
             dfs(candidate,target,index+1);
         }else{
           temp.push_back(candidate[index]);
           flag=1;
           dfs(candidate,target-candidate[index],index+1);
           temp.pop_back();
           flag=0;
           dfs(candidate,target,index+1);
         }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        dfs(candidates,target,0);
        return v;
    }
};
```
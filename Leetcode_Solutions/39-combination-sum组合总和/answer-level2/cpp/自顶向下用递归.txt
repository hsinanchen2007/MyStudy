### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> v;
    vector<int> temp;
    void dfs(vector<int>& candidates,int target,int num,int index){
        if(index>=candidates.size())
           return;
        if(num>target)
        {
           return;
        }
        if(num==target){
            v.push_back(temp);
            return;
        }
        num=num+candidates[index];
        temp.push_back(candidates[index]);
        dfs(candidates,target,num,index);
        num=num-candidates[index];
        temp.pop_back();
        dfs(candidates,target,num,index+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates,target,0,0);
        return v;
    }
};
```
### 解题思路
深度遍历

### 代码

```cpp
class Solution {
private:
    vector<vector<int>> ret;//保存结果
    vector<int> path;
    vector<int> candidates;
public:


    void DFS(int start,int target)
    {
        
        if(target==0)
        {
            ret.push_back(path);
            return;
        }
        for(int i=start;i<candidates.size()&&target-candidates[i]>=0;i++)
        {
            path.push_back(candidates[i]);
            DFS(i,target-candidates[i]);//递归
            path.pop_back();//如果在之前的递归没有return，说明结果不对，剪枝
        }
    }





    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        
        
        sort(candidates.begin(),candidates.end());//先排序
        this->candidates=candidates;
        DFS(0,target);

        return ret;
    

        
    }
};
```
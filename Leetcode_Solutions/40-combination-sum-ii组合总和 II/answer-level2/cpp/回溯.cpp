### 解题思路
先排序，去重的关键是同一层for循环遍历中碰到相邻元素相同的要跳过，不要重复判断

### 代码

```cpp
class Solution {
private:
vector<vector<int>>res;
vector<int>path;
vector<int>candidates;
int target;

public:
    void DFS(int t,int sum){
        
        if(sum==target){
            res.push_back(path);
            return;
        }
        for(int i = t;i<candidates.size()&&sum+candidates[i]<=target;i++){
            if(i==t||candidates[i]!=candidates[i-1]){
                path.push_back(candidates[i]);
                DFS(i+1,sum+candidates[i]);
                path.pop_back();
            }
        }  
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        this->candidates=candidates;
        this->target=target;
        sort(this->candidates.begin(),this->candidates.end());
        if(this->candidates[0]<=target)
            DFS(0,0);
        return res;
    }
};
```
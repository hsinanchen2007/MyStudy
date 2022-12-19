### 解题思路
函数参数加引用加速

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        DFS(0, candidates, 0, target, v);
        return vv;
    }
        void DFS(int n, vector<int> candidates, int sum, int target, vector<int> &v)
        {
            if(sum == target)
            {
                //sort(v.begin(), v.end());
                //if(find(vv.begin(), vv.end(), v) == vv.end())
                  vv.push_back(v);
                return ;
            }
            for(int i = n ; i < candidates.size() ; ++i)
            {
                if(sum + candidates[i] <= target)
                {
                     v.push_back(candidates[i]);
                     DFS(i, candidates, sum + candidates[i], target, v);
                     v.pop_back();
                }
            }
        }
private:
    vector<vector<int> > vv;
};
```
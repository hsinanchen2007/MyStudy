### 解题思路
跟39那道 Combination Sum 组合之和本质没有区别，只需要改动一点点即可，之前那道题给定数组中的数字可以重复使用，而这道题不能重复使用.
只需要在之前的基础上修改两个地方即可，首先在递归的for循环里加上if (i > start && num[i] == num[i - 1]) continue; 这样可以防止res中出现重复项，然后将递归调用combinationSum2DFS里面的参数换成i+1，这样就不会重复使用数组中的数字了。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int> out;
        sort(candidates.begin(),candidates.end());
        combinationSum2DFS(candidates,target,0,out,res);
        return res;
    }
    void combinationSum2DFS(vector<int> &num, int target, int start, vector<int> &out, vector<vector<int> > &res) {
        if (target < 0) 
        {
            return;
        }
        else if (target == 0) 
        {
            res.push_back(out);
        }
        else 
        {
            for (int i = start; i < num.size(); ++i) 
            {
                if (i > start && num[i] == num[i - 1]) //防止重复
                {
                    continue;
                }
                out.push_back(num[i]);
                combinationSum2DFS(num, target - num[i], i + 1, out, res);//注意i+1
                out.pop_back();
            }
        }
    }
};
```
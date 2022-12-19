### 解题思路
这道题和上一题类似，但是去重方面我没有想到很好的方法，还是用了排序+map<vector<int>, int>的方式进行去重
注意：必须要排序+map<vector<int>, int>，否则[7,1]与[1,7]存在重复


### 代码

```cpp
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> combination;
        map<vector<int>, int> table;
        getCombination(res, candidates, combination, target, 0, 0, table);

        return res;
    }

    void getCombination(vector<vector<int>> &res, vector<int>& candidates, vector<int>& combination, int target, int partial_sum, int idx, map<vector<int>, int> &table){
        if(partial_sum == target){
            if(table[combination] == 0){
                res.push_back(combination);
                table[combination]++;
            }
            return;
        }else if(partial_sum > target){
            return;
        }else{//partial_sum < target
            for(int i = idx; i < candidates.size(); ++i){
                partial_sum += candidates[i];
                combination.push_back(candidates[i]);
                getCombination(res, candidates, combination, target, partial_sum, i+1, table);
                partial_sum -= candidates[i];
                combination.pop_back();
            }
            return;
        }
    }
};
```
执行用时 : 56 ms , 在所有 C++ 提交中击败了 18.10% 的用户 
内存消耗 : 7.4 MB , 在所有 C++ 提交中击败了 100.00% 的用户
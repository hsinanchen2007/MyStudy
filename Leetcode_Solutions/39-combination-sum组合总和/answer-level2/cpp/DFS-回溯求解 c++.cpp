class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> results;
        vector<int> combination;
        sort(candidates.begin(), candidates.end());
        recursion(candidates, target, 0, combination, results);
        return results;
    }

private:
    //递归定义：找到所有以combination开头的和为target的组合
    //remainTarget为剩余需要加入combination的数
    void recursion(vector<int>& candidates, int remainTarget, int startIndex, 
                vector<int> combination, vector<vector<int>>& results)
                {
                    //递归出口
                    if(remainTarget == 0)
                    {
                        results.push_back(combination);
                        return;
                    }
                    //递归拆解
                    for(int i=startIndex; i<candidates.size();++i)
                    {
                        if(candidates[i]> remainTarget)
                        {
                            break;
                        }
                        combination.push_back(candidates[i]);
                        recursion(candidates, remainTarget-candidates[i],i,combination,results);
                        combination.pop_back();
                    }
                }
};
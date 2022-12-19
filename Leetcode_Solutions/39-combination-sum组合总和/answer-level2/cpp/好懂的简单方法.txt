利用递归相减的方法，减到零时将答案加入队列，小于零返回。
为防止重复答案禁止程序回头，每次递归从上一层进入时的位置开始。
没有过多优化剪枝，一看就懂。
```
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        find(0, target, result, temp, candidates);
        return result;
    }
    void find(int low, int now, vector<vector<int>>& result, vector<int>& temp, vector<int>& candidates){
        if(now==0) result.push_back(temp);
        if(now<0) return;
        for(int i=low; i<candidates.size(); i++){
            temp.push_back(candidates[i]);
            find(i, now-candidates[i], result, temp, candidates);
            temp.pop_back();
        }
    }
};
```

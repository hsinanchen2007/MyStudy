比较典型的深搜回溯，先一个数重复到底，然后拿掉这个数，回溯
```
class Solution {
public:
    set<vector<int>> int_set;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        if(candidates.size() == 0) return res;
        int sum = 0;
        sort(candidates.begin(),candidates.end());
        vector<int> path;
        generate(candidates,target,0,path,res,0);
        return res;
    }
private:
    void generate(vector<int> &candidates,int target,int sum,vector<int> &path,vector<vector<int>> &res,int i){
        if(i >= candidates.size() || candidates[i]>target || sum >= target) return ;
        path.push_back(candidates[i]);
        sum += candidates[i];
        if(sum == target && int_set.find(path) == int_set.end()) res.push_back(path);
        generate(candidates,target,sum,path,res,i);
        sum -= candidates[i];
        path.pop_back();
        generate(candidates,target,sum,path,res,i+1);
    }
};
```


```
class Solution {
void backtrack(vector<int>& candidates,int target,vector<vector<int>>& ans,
    vector<int>& cur, int index){
        if(target == 0){ans.push_back(cur);return;}
        if(index == candidates.size())return;
        int num = candidates[index];
        if(num > target) return;
        backtrack(candidates, target, ans, cur, index+1);
        for(int i = 1; i*num <= target; ++i)
        {
            cur.push_back(num);
            backtrack(candidates, target-i*num, ans, cur, index+1);
        }
        while(cur.size() >= 1 && cur[cur.size()-1] == num)cur.pop_back();
    }
public:
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> cur;
        backtrack(candidates,target,ans,cur,0);
        return ans;
    }
};
```


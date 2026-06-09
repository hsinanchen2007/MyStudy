直接用39题的代码会产生输出的结果中可能有重复的。
所以，在39的基础加入了map，先把每次的结果作为key存进map，最后再把map中所有的key放进res，这样最后的答案就不会有重复的了。
代码：
```
class Solution {
public:
    map<vector<int>, int> item;
    void backtrack(vector<int>& candidates, int target, int sum, int first, vector<int>& nums){
        if(sum == target){
            item[nums] = 1;
            return;
        }
        for(int i=first; i<candidates.size(); i++){
            if(sum+candidates[i] <= target){
                nums.push_back(candidates[i]);
                backtrack(candidates, target, sum+candidates[i], i+1, nums);
                nums.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> nums;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, 0, nums);
        for(auto t:item){
            res.push_back(t.first);
        }
        return res;
    }
};
```

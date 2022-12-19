由于题目要求不能重复，所以我们进行递归的时候要记录我们运算的索引，判断时从当前索引值开始，递归则索引值加1，并且记录目前为止的和。
递归的终止条件是：sum==target。
另外，没有用到map或者set的原因是，在回溯之前，我们进行了对下一位数字的判断，如果是相同的，就舍弃；因而不会有重复的集合出现。而且数据没有丢失，这是因为它的上个数在递归过程中能用到它（若它满足条件）。
```
class Solution {
public:
    void backtrack(vector<int>& candidates, int target, int sum, int begin){
        if(sum == target) {
            res.push_back(nums);
            return;
        } else
            while(begin<candidates.size() && sum+candidates[begin] <= target) {
                nums.push_back(candidates[begin]);
                backtrack(candidates, target, sum+candidates[begin++], begin);
            //回溯前去重
                while(begin<candidates.size() && candidates[begin] == candidates[begin-1]) ++begin;
                nums.pop_back();//回溯，进行下一位运算  
            }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if(candidates.empty()){return res;}
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, 0);
        return res;
    }
private:
    vector<vector<int>> res;
    vector<int> nums;
};
```

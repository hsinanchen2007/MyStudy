回溯法 practice [继leetcode39题](https://leetcode-cn.com/problems/combination-sum/solution/zu-he-zong-he-by-neneda/) 之后
```cpp
class Solution {
private:
    vector< vector<int> > res;
    
    //相比较 leetcode 39，改动3处
    // # 1. 先进行了排序
    // # 2. 在每一层的选择中，不选重复的，遇见重复数字跳过
    // # 3. i 改为 i+1 每个元素只使用一次
    // example： candidates = [2,5,2,1,2], target = 5,
    void findCombinationSum2(const vector<int> & candidates, int target, int index, vector<int> &p) {

        if(target == 0) {
            res.push_back(p);
            return;
        }
        // if (target < 0) {
        //     return;
        // }
        for (int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i] == candidates[i-1]) //change #2
                continue;
            if (target >= candidates[i]){
                p.push_back(candidates[i]);
                findCombinationSum2(candidates, target-candidates[i], i+1, p);  //change #3
                p.pop_back();
            }
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        if (candidates.size() == 0)
            return res;
        
        sort(candidates.begin(), candidates.end());  // change #1

        vector<int> p;
        findCombinationSum2(candidates, target, 0, p);
        return res;
    }
};
```
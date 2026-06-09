### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size() < 2) return {nums};
        vector<int> decisions;
        backTrack(nums, decisions);
        return res;
        
    }
    void backTrack(vector<int> &options, vector<int>& decisions) {
        if(decisions.size() == options.size()) {//终止条件： 到达根节点
            res.push_back(decisions);
            return;
        }
        for(int i : options) {
            if(find(decisions.begin(), decisions.end(), i) == decisions.end()) {
                decisions.push_back(i);
                backTrack(options, decisions);
                decisions.pop_back();
            }
            else
                continue;
        }
    }
private:
    vector<vector<int>> res;
};
```
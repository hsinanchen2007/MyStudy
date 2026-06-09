### 解题思路
回溯法（递归）
创建一个空集trace，遍历数组元素，如果当前元素已经在trace中，跳过；如果不在trace中，则加入到trace中，然后再递归加下一个元素到trace中，直到trace中元素个数等于数组中的元素个数（至此得到了一个全排列结果）；需要注意的是从一次递归返回时要吐出刚才加入的元素
### 代码

```cpp
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> trace = {};
        do_permute(nums, trace, res);
        return res;
    }
    void do_permute(const vector<int> &nums, vector<int> &trace, vector<vector<int>> &res) {
        if (trace.size() == nums.size()) {
            res.push_back(trace);
        }
        for (int i = 0; i < nums.size(); ++i) {
            // 如果当前元素在trace中，跳过
            if (in_trace(trace, nums[i])) {
                continue;
            }
            // 把当前元素加入到trace中
            trace.push_back(nums[i]);            
            do_permute(nums, trace, res);
            // 恢复到原状态
            trace.pop_back();
        }
    }
    bool in_trace(const vector<int> &trace, int val) {
        for (int i = 0; i < trace.size(); ++i) {
            if (trace[i] == val) {
                return true;
            }
        }
        return false;
    }
};
```
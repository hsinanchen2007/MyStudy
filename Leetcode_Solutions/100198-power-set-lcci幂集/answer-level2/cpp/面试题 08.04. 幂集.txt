子集的个数为“2^集合元素个数”。对每个元素，在原来结果的基础上，有保持原状和增加本元素两个可能。
方法一：迭代
```
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res({{}});
        for(size_t i = 0; i < nums.size(); i++) {
            size_t count = res.size();
            for(size_t j = 0; j < count; j++) {
                vector<int> tmp(res[j]);
                tmp.push_back(nums[i]);
                res.emplace_back(tmp);
            }
        }
        return res;
    }
};
```
方法二：递归
```
class Solution {
private:
    void Dfs(vector<vector<int>>& res, vector<int>& nums, size_t idx, vector<int>& arr) {
        if(idx >= nums.size()) {
            res.push_back(arr);
            return;
        }
        arr.push_back(nums[idx]);
        Dfs(res, nums, idx + 1, arr);

        arr.pop_back();
        Dfs(res, nums, idx + 1, arr);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> arr;
        Dfs(res, nums, 0, arr);
        return res;
    }
};
```



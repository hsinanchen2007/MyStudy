### 解题思路
1、递归 + 排序去重

### 代码

```cpp
class Solution {
public:
    void subsets(vector<int>& nums, int index, vector<int>& v, vector<vector<int>>& res)
    {
        if (index == nums.size())
        {
            sort(v.begin(), v.end());
            res.push_back(v);
            return;
        }

        subsets(nums, index + 1, v, res);

        vector<int> v_tmp = v; //使用临时数组
        v_tmp.push_back(nums.at(index));
        subsets(nums, index + 1, v_tmp, res);
    }



    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        vector<vector<int>> res;
        res.reserve(pow(2, nums.size()));

        vector<int> v_tmp;
        v_tmp.reserve(nums.size());
        subsets(nums, 0, v_tmp, res);

        sort(res.begin(), res.end());
        auto iter = unique(res.begin(), res.end());
        res.resize(iter - res.begin());

        return res;
    }
};
```
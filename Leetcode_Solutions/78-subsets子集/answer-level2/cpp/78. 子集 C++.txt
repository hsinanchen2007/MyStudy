### 解题思路
1、递归

### 代码

```cpp
class Solution {
public:

    //递归函数
    void subsets(vector<int>& nums, int index, const vector<int>& v, vector<vector<int>>& res)
    {
        if (index == nums.size())
        {
            res.push_back(v);
            return;
        }

        subsets(nums, index + 1, v, res);

        vector<int> v_tmp = v; //使用临时数组
        v_tmp.push_back(nums.at(index));
        subsets(nums, index + 1, v_tmp, res);
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> res;
        res.reserve(pow(2, nums.size()));

        vector<int> v;
        v.reserve(nums.size());
        subsets(nums, 0, v, res);

        return res;
    }
};
```
### 解题思路
1、递归

### 代码

```cpp
class Solution {
public:
    void permute(const vector<int>& nums, int index, vector<int>& v, vector<vector<int>>& res)
    {
        if (index == nums.size())
        {
            res.push_back(v);
            return;
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            if (find(v.begin(), v.end(), nums.at(i)) != v.end()) //数字已选择
            {
                continue;
            }
            
            vector<int> tmp = v;
            tmp.push_back(nums.at(i));

            permute(nums, index + 1, tmp, res);
        }
    }


    vector<vector<int>> permute(vector<int>& nums) {

        int size = 1;
        for (int i = 1; i <= nums.size(); ++i)
        {
            size *= i;
        }

        vector<vector<int>> res;
        res.reserve(size);

        vector<int> tmp;
        tmp.reserve(nums.size());
        permute(nums, 0, tmp, res);

        return res;
    }
};
```
### 解题思路
对每一个元素，考虑加入数组或者不加入数组
### 代码

```cpp
class Solution {
public:
    void search(vector<int>& nums, int begin, int end, vector<int> &tmp, vector<vector<int>> &res)
    {
        if(begin == end){
            res.push_back(tmp);
            return;
        }      
        search(nums, begin + 1, end, tmp, res);
        tmp.push_back(nums[begin]);
        search(nums, begin + 1, end, tmp, res);
        tmp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.empty())
            return {};
        vector<int> tmp;
        vector<vector<int>> res;
        search(nums, 0, nums.size(), tmp, res);
        return res;

    }
};
```
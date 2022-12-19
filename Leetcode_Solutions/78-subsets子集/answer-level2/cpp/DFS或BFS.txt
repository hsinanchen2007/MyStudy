### 解题思路
和上一题一样的思路，DFS即可

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> valid_res;
        getCombination(res, valid_res, nums, 0);
        return res;
    }

    void getCombination(vector<vector<int>> &res, vector<int> &valid_res, vector<int>& nums, int idx){
        if(valid_res.size() > nums.size()){
            return;
        }else{
            res.push_back(valid_res);
            for(int i = idx; i < nums.size(); ++i){
                valid_res.push_back(nums[i]);
                getCombination(res, valid_res, nums, i+1);
                valid_res.pop_back();
            }
        }
    }
};
```

### 结果
执行用时 : 4 ms , 在所有 C++ 提交中击败了 76.27% 的用户 
内存消耗 : 7.2 MB , 在所有 C++ 提交中击败了 100.00% 的用户
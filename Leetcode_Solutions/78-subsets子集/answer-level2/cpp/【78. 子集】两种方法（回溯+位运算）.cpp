### 思路一：回溯
对每个数，要么加入要么不加入结果集中。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.empty()) return res;
        vector<int> cur;
        helper(nums, res, 0, cur);
        return res;       
    }
    void helper(vector<int> &nums, vector<vector<int>> &res, int pos, vector<int> &cur) {
        res.push_back(cur);
        for (int i = pos; i < nums.size(); ++i) {
            cur.push_back(nums[i]);
            helper(nums, res, i + 1, cur);
            cur.pop_back();
        }
    }
};
```

### 思路二：位运算
每个数对应一个二进制，每位要么取要么不取。
1 | 2 | 3
-- |-- | --
0 | 0 | 0
0 | 0 | 1
0 | 1 | 0
0 | 1 | 1
1 | 0 | 0
1 | 0 | 1
1 | 1 | 0
1 | 1 | 1

### 代码
```c++
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.empty()) return res;
        int size = nums.size();
        int n = 1 << size;        
        for (int i = 0; i < n; ++i) {
            vector<int> tmp;
            for (int j = 0; j < size; ++j) {
                if (i & (1 << j)) { 
                    tmp.push_back(nums[j]);
                }
            }
            res.push_back(tmp);
        }        
        return res;       
    }
};
```

### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/a8c7df7f018a95358b37d3d60a785539508dfa811ef5e315dcc0657c86e7fb48-image.png)

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res ={};
        if (nums.empty()) {
            return res;
        }
        vector<int> combination;
        vector<int> repeat(nums.size(),0);
        DFS(nums,res,combination, repeat);
        return res;
    }

    void DFS(vector<int>& nums, vector<vector<int>> &res, vector<int> combination, vector<int> &repeat)
    {
        if(combination.size() == nums.size()) {
            res.emplace_back(combination);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (repeat[i] == 1) {
                continue;
            }
            repeat[i] = 1;
            combination.push_back(nums[i]);
            DFS(nums,res,combination, repeat);
            combination.pop_back();
            repeat[i] = 0;
        }
    }
};
```
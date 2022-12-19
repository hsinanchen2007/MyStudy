### 解题思路
回溯法
关键点：用一个数组表示棋盘，i 代表行，nums[i]代表列，行列初始后不存在行列冲突，回溯时仅检查斜向冲突，之后采用类似全排列的回溯算法来遍历所有情况


### 代码

```cpp
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        // 存棋盘，i 代表行，nums[i]代表列，行列初始后不存在行列冲突，回溯时仅检查斜向冲突
        vector<int> nums(n, 0);
        for (int i = 0; i < n; i++) nums[i] = i;
        // 回溯
        vector<vector<string>> res;
        dfs(res, nums, 0);
        return res;
    }

    void dfs(vector<vector<string>>& res, vector<int>& nums, int start){
        // 斜线减枝
        for (int i = 0; i < start-1; i++){
            if (abs(nums[start-1]-nums[i]) == start-i-1) return;
        }
        // 输出
        if (start == nums.size()){
            vector<string> tmp;
            for (int v : nums){
                string s(nums.size(), '.');
                s[v] = 'Q';
                tmp.push_back(s);
            }
            res.push_back(tmp);
            return;
        }
        // 迭代
        for (int i = start; i < nums.size(); i++){
            swap(nums[i], nums[start]);
            dfs(res, nums, start+1);
            swap(nums[i], nums[start]);
        }
    }
};
```
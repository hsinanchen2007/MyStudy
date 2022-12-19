### 解题思路
// 官方题解二：回溯算法
// 根据labuladong的题解，回溯算法是有模板的。https://leetcode-cn.com/problems/subsets/solution/hui-su-si-xiang-tuan-mie-pai-lie-zu-he-zi-ji-wen-t/

// result=[]
// def backtrack(路径，选择列表)  // 路径就是result中满足的每一个元素。  选择列表一般就是题目给定的nums范围
        // if 满足条件：
            // result.add(路径)
            // return
        // for 选择 in 选择列表:
            // 做选择，即将此选择添加到列表中
            // backtrack(路径，选择列表)
            // 撤销选择，即一步步的回退到原始状态去，将紧挨着的那个做的选择悔棋，反悔。

### 代码

```cpp

class Solution {
    // 那首先需要将返回的结果定义出来
    vector<vector<int>>  res;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> path;
        // 定义回溯算法: 选择列表nums, 路径定义出来
        backtrack(path, nums, 0);
        return res;
        
    }
    void backtrack(vector<int> &path, vector<int>& nums, int start) {
        // 那结束条件是什么呢？由于此题求得是子集，其实就是把 nums中的每个元素都使用到即可
        // 那其实任何一条路径都是满足题意的，所以直接添加到 res 中即可
        // 但是为了避免子集反复求，那的定义个索引，以便遍历nums， 这个索引我们称为start, start 最开始是从0开始的。
        // 所以改变 backtrack(path, nums);  ==》 backtrack(path, nums, start);
        res.push_back(path);

        for(int i = start; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtrack(path, nums, i+1); // i添加到之后，就应该用i之后的，所以这里 i+1
            path.pop_back();
        }

    }
};
```
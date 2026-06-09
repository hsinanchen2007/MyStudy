是一道典型的搜索题，很值得好好研究一下套路，之前碰到这种题目重复的情况总是写不太清楚。
在dfs里加一个unordered_set，用来标记是否已经添加过某一个数字是非常有用的。如果有的话，就跳过，因为默认的深搜策略会把同样的数字在之后的dfs里都选上，因为这个set是在dfs里声明的，所以调用的时候之前的状态相当于被清空了。
这样的话，就可以做到同样的数字，取一个到取全部，每个情况都遍历了。
![Screen Shot 2020-02-10 at 6.05.21 PM.png](https://pic.leetcode-cn.com/00be616d54eba5b921b29fe941caff4ac7c7becabdd455311e9998ba8cfd0d30-Screen%20Shot%202020-02-10%20at%206.05.21%20PM.png)

[自己动手实现分布式缓存](https://github.com/wfnuser/burrow)
[我的题解](https://www.github.com/wfnuser/leetcode)
[我的github](https://www.github.com/wfnuser)
欢迎大家在github follow我 对分布式缓存感兴趣的可以看第一个项目，希望之后可以发布更多的玩具项目
```
class Solution {
public:
    vector<vector<int>> ans;

    void dfs(vector<int>& nums, vector<int>& path, int start) {
        if (path.size() >= 2) ans.push_back(path);
        if (start >= nums.size()) return;
        unordered_set<int> s;
        // 如果set里已经记录了当前的值，则跳过；因为之前唤起的dfs里会把之后所有的同样的值都选中；
        // 只需要考虑从之后开始选中的重复的值即可
        for (int i = start; i < nums.size(); i++) {
            if (s.find(nums[i]) != s.end()) continue;
            if (path.size() == 0) {
                s.insert(nums[i]);
                path.push_back(nums[i]);
                dfs(nums, path, i+1);
                path.pop_back();
            } else {
                if (nums[i] >= path.back()) {
                    s.insert(nums[i]);
                    path.push_back(nums[i]);
                    dfs(nums, path, i+1);
                    path.pop_back();
                }
            }
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> path;
        dfs(nums, path, 0);
        return ans;
    }
};
```

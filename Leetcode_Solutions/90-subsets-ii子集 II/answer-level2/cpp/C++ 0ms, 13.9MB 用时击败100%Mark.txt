### 解题思路
数据处理 + 深搜

![image.png](https://pic.leetcode-cn.com/70fbd84a7fdcc69d2b8f6bfe2c9f3264d4e16f2c1efce4a7b70da05cd831f79f-image.png)

### 代码

```cpp
class Solution {
public:
    vector<int> cnt, tmp;
    vector<vector<int>> ans;
    // 深度优先搜索
    void dfs(vector<int>& nums, int dep)
    {
        // 遍历完所有数，存储答案
        if(dep < 0)
        {
            ans.push_back(tmp);
            return;
        }
        // 不取当前数
        dfs(nums, dep - 1);
        // 取 i 个当前数
        for(int i = 1; i <= cnt[dep]; i ++)
        {
            tmp.push_back(nums[dep]);
            dfs(nums, dep - 1);
        }
        // 清空，回溯
        tmp.erase(tmp.end() - cnt[dep], tmp.end());
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // 对所有数据排序
        sort(nums.begin(), nums.end());
        // k 中记录所有不重复的数的总个数，cnt 中计算每个数出现的次数
        int k = 0;
        cnt.push_back(1);
        for(int i = 1; i < nums.size(); i ++)
        {
            if(nums[i] == nums[k])
            {
                cnt[cnt.size() - 1] ++;
                continue;
            }
            cnt.push_back(1);
            k ++;
            nums[k] = nums[i];
        }
        // 深搜
        dfs(nums, k);
        return ans;
    }
};
```
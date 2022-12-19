### 解题思路
深度优先搜索

![image.png](https://pic.leetcode-cn.com/50783d153956ba096fea269eae565b4530b4cf2b69bd3d7c5ee3c11737fb59c0-image.png)

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> tmp;
    void find(int dep, vector<int>& nums)
    {
        // 已经处理完最后一位，将目前存储的集合存入 ans ，并回溯
        if(dep <= 0)
        {
            ans.push_back(tmp);
            return;
        }
        // 情况一：集合中有该元素
        tmp.push_back(nums[dep - 1]);
        find(dep - 1, nums);
        tmp.pop_back();
        // 情况二：集合中无该元素
        find(dep - 1, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        find(nums.size(), nums);
        return ans;
    }
};
```
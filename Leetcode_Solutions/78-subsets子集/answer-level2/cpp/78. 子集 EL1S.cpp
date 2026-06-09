两种方法
子集是求组合数。[46题](https://leetcode-cn.com/problems/permutations/solution/46-quan-pai-lie-by-uqisn4nwiw/) [47题](https://leetcode-cn.com/problems/permutations-ii/solution/47-quan-pai-lie-ii-el1s-by-uqisn4nwiw/)是求排列数
![image.png](https://pic.leetcode-cn.com/1dfaca1c09ab8caeaf2259a663e275fb7f5e331091ab1d57a2f4f405744600d0-image.png)

第一种循环
```
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        res.push_back({});
        for(auto x: nums)
        {
            int len = res.size();
            for(int i = 0; i < len; i++)
            {
                auto tmp = res[i];
                tmp.push_back(x);
                res.push_back(tmp);
            }
        }
        return res;
    }
};
```


第二种dfs
```
class Solution {
    vector<vector<int>> res;
    vector<int> nums;
    void dfs(long long idx)
    {
        if(idx == nums.size())
            return;
        int len = res.size();
        for(int i = 0; i < len; i++)
        {
            auto tmp = res[i];
            tmp.push_back(nums[idx]);
            res.push_back(tmp);
        }
        dfs(idx + 1);
    }
public:
    vector<vector<int>> subsets(vector<int>& _nums) {
        nums = _nums;
        res.push_back({});
        dfs(0);
        return res;
    }
};
```


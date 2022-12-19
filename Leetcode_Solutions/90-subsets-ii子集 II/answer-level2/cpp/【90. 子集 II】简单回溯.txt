### 思路
在[子集](https://leetcode-cn.com/problems/subsets/solution/78-zi-ji-jian-dan-hui-su-ji-bai-9964-by-guohaoding/)上加去重。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.empty()) return res;
        vector<int> cur;
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        helper(nums, res, 0, cur, st);
        return res;
    }

    void helper(vector<int> &nums, vector<vector<int>> &res, int pos, vector<int> &cur, set<vector<int>> &st) {
        if (st.count(cur) == 0) {
            st.insert(cur);
            res.push_back(cur);            
        }
        for (int i = pos; i < nums.size(); ++i) {
            cur.push_back(nums[i]);
            helper(nums, res, i + 1, cur, st);
            cur.pop_back();
        }
    }
};
```
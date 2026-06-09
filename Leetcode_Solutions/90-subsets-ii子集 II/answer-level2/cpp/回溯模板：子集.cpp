### 解题思路

[子集](https://leetcode-cn.com/problems/subsets/) 的加强版，思路见代码注释。

### 代码

```cpp
class Solution {
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> empty;
        // 排序
        sort(nums.begin(), nums.end());
        backtrack(nums, empty, 0);
        return res;
    }
    
    void backtrack(vector<int>& nums, vector<int>& cur, int i) {
        // 边界
        if(i > nums.size())
            return;
        res.push_back(cur);
        int j = i;
        while(j<nums.size()) {
            int k = j;
            int cnt = 1;
            while(k+1 < nums.size() && nums[k+1] == nums[k])
                k++, cnt++;

            // nums[j] 重复 0 ~ cnt次
            for(int p=0; p<cnt; p++) {
                cur.push_back(nums[j]);
                backtrack(nums, cur, k + 1);
            }
            while(cnt--)
                cur.pop_back();
            // 下一个不同数字
            j = k + 1;
        }
    }
};
```

对比经典子集模板：

```cpp
class Solution {
private:
    vector<vector<int>> res;
    int n;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        vector<int> a;
        backtrack(nums, a, 0);
        return res;
    }
    
    void backtrack(vector<int>& nums, vector<int>& cur, int i) {
        if(i > n)
            return;
        res.push_back(cur);
        for(int j=i; j<n; j++) {
            cur.push_back(nums[j]);
            backtrack(nums, cur, j + 1);
            cur.pop_back();
        }
    }
};
```

主要思路和子集那题一样，就是要去重
**选的情况**：pos == 0 || nums[pos-1] != nums[pos] || visted[pos-1]
1.位置是第一个
2.前一个不等于当前
3.前一个数字必定选   
三个条件必定满足一个
**没选的情况**：继续递归

```
class Solution {
public:
    void dfs(vector<int>& nums, vector<vector<int>>& result, vector<int>& list, vector<int>& visted, int pos) {
        if (pos==nums.size())
        {
            result.push_back(list);
            return;
        }
        if (pos == 0 || nums[pos-1] != nums[pos] || visted[pos-1]) {//选以及选的条件
            list.push_back(nums[pos]);
            visted[pos] = 1;
            dfs(nums, result, list, visted, pos + 1);
            visted[pos] = 0;
            list.pop_back();
        }
        dfs(nums, result, list, visted, pos + 1);//不选
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> list;
        vector<int> visted(nums.size(),0);
        dfs(nums, result, list, visted, 0);
        return result;
    }
};
```

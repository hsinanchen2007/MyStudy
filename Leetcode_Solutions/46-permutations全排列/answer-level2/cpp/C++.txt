### 解题思路
详情看代码，
最开始考虑会有重复，使用的set来保存结果去重，最后遍历加入到vector中
后来想想，因为元素不同，因此不会出现重复序列，所以直接使用vector即可
修改之后成了双百代码

### 代码

```cpp
class Solution {
public:
    
    void dfs(vector<int>& nums, int start, vector<vector<int>>& ans) {
        if (start == nums.size()) {
            //ans.insert(nums);
            ans.push_back(nums);
            return;
        }
        // 重点就是这里的理解，
        // 将start后(包括start)每一位与当前start位交换, 去进行搜索，
　　　　　// 搜索完之后，要把刚才的换回来，便于后面的位正常与start位进行交换
        for (int i = start; i < nums.size(); i++) {
            int tmp = move(nums[start]);
            nums[start] = move(nums[i]);
            nums[i] = move(tmp);
            
            dfs(nums, start + 1, ans);
            
            tmp = move(nums[start]);
            nums[start] = move(nums[i]);
            nums[i] = move(tmp);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        // set<vector<int>> ans;
        
        int start = 0;
        vector<vector<int>> result;
        if (nums.size() == 0) {
            return result;
        }
        dfs(nums, start, result);
        /*
        set<vector<int>>::iterator it;
        for (it = ans.begin(); it != ans.end(); it++) {
            result.push_back(*it);
        }
        */
        return result;
    }
};
```
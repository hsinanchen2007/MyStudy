注意先排序

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 0 ; i <= nums.size() ; ++i)
        {
            vector<int> path;
            DFS(0, i, nums, path);
        }
        return ans;
    }
    void DFS(int st, int n, vector<int>& nums, vector<int>& path)
    {
        if(path.size() == n)
        {
            //if(find(ans.begin(), ans.end(), path) == ans.end())
                 ans.push_back(path);
            return ;
        }
        for(int i = st ; i < nums.size() ; ++i)
        {
            if(i > st && nums[i] == nums[i - 1])
                continue;
            path.push_back(nums[i]);
            DFS(i + 1, n, nums, path);
            path.pop_back();
        }
    }
private:
    vector<vector<int> > ans;
};
```
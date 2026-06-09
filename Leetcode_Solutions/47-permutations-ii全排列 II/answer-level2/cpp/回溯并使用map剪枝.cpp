### 解题思路
和全排列I的方式类似，不同的是使用map替代之前的标记数组。
每次分叉只能分出不重复且还有值的分支。

### 代码

```cpp
class Solution {
private:
    vector<vector<int>> res;
    vector<int> item;
public:
    void dfs(int level, int len, unordered_map<int, int>& num_map){
        if(level == len)res.push_back(item);
        else for(auto &it: num_map){
            if(it.second > 0){
                it.second--;
                item.push_back(it.first);
                dfs(level+1, len, num_map);
                item.pop_back();
                it.second++;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int, int> num_map;
        for(int num : nums){
            num_map[num]++;
        }
        dfs(0, nums.size(), num_map);
        return res;
    }
};
```
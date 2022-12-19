### 解题思路

## 时间复杂度：O(n!)   空间：O(n)
### 代码
## 方法一：递归

```python []
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:     
        if len(nums) <= 1: return [nums]
        
        res = []
        for i, num in enumerate(nums):
            rest = nums[:i] + nums[i+1:]
            for rest_num in self.permute(rest):
                res.append([num] + rest_num)
        return res
```

## 方法二：枚举可能的数字给当前的位置
![截屏2020-03-15下午9.23.49.png](https://pic.leetcode-cn.com/1c719b34d273b93816e08c196d27f117d50c398e59968027447bec78f841cfc8-%E6%88%AA%E5%B1%8F2020-03-15%E4%B8%8B%E5%8D%889.23.49.png)

写法A：推荐
![截屏2020-03-15下午9.20.12.png](https://pic.leetcode-cn.com/78a136db69b9bc1e5e50252a518fc72208598de4423327b8e3ba64d0939c2d43-%E6%88%AA%E5%B1%8F2020-03-15%E4%B8%8B%E5%8D%889.20.12.png)
```cpp []
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path(nums.size());
        vector<bool> used(nums.size(), false); // true if nums[i] is used
        dfs(0, nums, res, used, path);
        return res; 
    }
    // cur_pos is the index to path
    void dfs(int cur_pos, const vector<int>& nums, vector<vector<int> > & res, vector<bool> & used, vector<int> & path) {
        if (cur_pos == nums.size()) {
            res.push_back(path);
            return;
        }
        //枚举可能的数字为当前的位置
        for (int i = 0; i < nums.size(); ++ i) {
            if (!used[i]){
                used[i] = true;
                path[cur_pos] = nums[i];
                dfs(cur_pos+1, nums, res, used, path);
                //恢复可使用，不需要恢复路径，因为它将被覆盖被下一个值
                used[i] = false;
            }
        }
    }
};

```

![截屏2020-03-15下午9.50.41.png](https://pic.leetcode-cn.com/977b85ad3c46652cf6a2f3c128dbe6c9b748309d3db7a1fdc576adaeb7d1c15f-%E6%88%AA%E5%B1%8F2020-03-15%E4%B8%8B%E5%8D%889.50.41.png)
写法B：

```cpp []
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        vector<bool> used(nums.size(), false); // true if nums[i] is used
        dfs(nums, res, used, path);
        return res; 
    }
    void dfs(const vector<int>& nums, vector<vector<int> > & res, vector<bool> & used, vector<int> & path) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        //枚举可能的数字给当前的位置
        for (int i = 0; i < nums.size(); ++ i) {
            if (!used[i]){
                used[i] = true;
                path.push_back(nums[i]);
                dfs(nums, res, used, path);
                //恢复当前位置为下一个可能的数字
                path.pop_back();
                used[i] = false;
            }
        }
    }
};

```


## 方法三：enumerate possible positions for current number
![截屏2020-03-15下午9.38.12.png](https://pic.leetcode-cn.com/65baac0763b324d30369aa418eb2bab97d6798e2308ffb181936d3f2c8d6ba52-%E6%88%AA%E5%B1%8F2020-03-15%E4%B8%8B%E5%8D%889.38.12.png)

![截屏2020-03-15下午10.06.37.png](https://pic.leetcode-cn.com/ef2840173f25d8a93a98dd22af85275546f68a87be91c82c3542e0fda75a90ce-%E6%88%AA%E5%B1%8F2020-03-15%E4%B8%8B%E5%8D%8810.06.37.png)
推荐

```cpp []
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path(nums.size());
        vector<bool> used(nums.size(), false); // true if path[i] is used
        dfs(0, nums, res, used, path);
        return res; 
    }
    // cur_num is the index to nums
    void dfs(int cur_num, const vector<int>& nums, vector<vector<int> > & res, vector<bool> & used, vector<int> & path) {
        if (cur_num == nums.size()) {
            res.push_back(path);
            return;
        }
        // enumerate possible positions for current number
        for (int i = 0; i < path.size(); ++ i) {
            if (!used[i]){
                used[i] = true;
                path[i] = nums[cur_num];
                dfs(cur_num+1, nums, res, used, path);
                // restore for used, no need to restore path because it will be overwritten in the next iterations
                used[i] = false;
            }
        }
    }
};

```


### 解题思路

执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户


跳过当前： subsets(nums, height+1, cur);
遍历当前： cur.push_back(nums[height]); subsets(nums, height+1, cur);

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> rt;
    void subsets(vector<int>& nums, int height, vector<int> cur){
        if(height == nums.size()){
            rt.push_back(cur);
            return;
        }
        subsets(nums, height+1, cur);
        cur.push_back(nums[height]);
        subsets(nums, height+1, cur);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        subsets(nums, 0, cur);
        return rt;
    }
};
```
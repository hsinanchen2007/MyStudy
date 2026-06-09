### 解题思路
这道题比较好的地方在于不用剪枝。

### 代码

```cpp
class Solution {
public:
    void permute_core(vector<int> nums, vector<vector<int>> & re, vector<int> & t, int pos, int & size) {
        if (pos == size) {
            re.push_back(t);
            return;
        }
        else {
            for (int i=0; i<nums.size(); i++) {
                t.push_back(nums[i]);
                int k=nums[i];
                nums.erase(nums.begin()+i);
                permute_core(nums, re, t, pos+1, size);
                nums.insert(nums.begin()+i, k);
                t.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> re;
        if (nums.size() == 0) return re;
        vector<int> t;
        int k=nums.size();
        permute_core(nums, re, t, 0, k);
        return re;
    }
};
```
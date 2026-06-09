### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
private:
    vector<vector<int>> res;
    vector<int> tmp;

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        generate(nums);

        return res;        
    }

    void generate(vector<int>& nums) {
        if (nums.size() == 0) {
            res.push_back(tmp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            vector<int> one = nums;
            one.erase(one.begin() + i);
            tmp.push_back(nums[i]);
            generate(one);
            tmp.pop_back();
        }

    }
};
```
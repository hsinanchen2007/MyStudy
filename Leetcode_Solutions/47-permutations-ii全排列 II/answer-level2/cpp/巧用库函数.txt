### 解题思路
注意排序

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > v;
        sort(nums.begin(), nums.end());
        do{
            v.push_back(nums);
        }while(next_permutation(nums.begin(), nums.end()));
        return v;
    }
};
```
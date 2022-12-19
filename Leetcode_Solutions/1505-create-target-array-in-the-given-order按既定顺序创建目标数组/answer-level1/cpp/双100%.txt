### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            res.insert(res.begin()+index[i],nums[i]);
        }
        return res;
    }
};
```
### 解题思路
代碼部分含有set及相關函數

### 代码

```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> hs;
        for(int i=0;i<nums.size();i++)
        {
            if(hs.count(nums[i])) return true;
            else hs.insert(nums[i]);
        }
        return false;
    }
};
```
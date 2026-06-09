### 解题思路
如果i从1开始就不要加一开始的判断了，这个点对于菜鸟来说经常搞错

### 代码

```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if (nums.size()==0)
        return false;
        for(int i =0;i< nums.size()-1;i++)
        {
            if(nums[i]==nums[i+1])
            {
                return true;
            }
        }
        return false;
    }
};
```
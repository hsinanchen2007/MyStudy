

### 代码

```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int i;
        vector<int> a(nums.size());
        for(i=0 ; i<nums.size() ; i++)
            a[i] = 0;
        for(i=0 ; i<nums.size() ; i++)
        {
            if(a[nums[i]] == 0)
                a[nums[i]] = 1;
            else
                return nums[i];
        }
        return 0;
    }
};
```
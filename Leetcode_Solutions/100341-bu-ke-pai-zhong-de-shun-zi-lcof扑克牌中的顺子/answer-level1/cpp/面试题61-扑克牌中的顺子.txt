### 解题思路
将数组排序后，判断数字产生的间隔与数组中0的个数即可。
由于数组很小，所以直接sort也不花时间。

### 代码

```cpp
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        // spe

        // func
        sort(nums.begin(),nums.end());
        int countGap = 0;
        int countZero = 0;
        for(int i = 0;i<nums.size()-1;i++)
        {
            if(nums[i] == 0)
            {
                ++countZero;
                continue;
            }
            else
            {
                if(nums[i] == nums[i+1])
                    return false;
                countGap += nums[i+1]-nums[i]-1;
            }
        }
        if(countGap <= countZero)
            return true;
        else
            return false;
    }
};
```
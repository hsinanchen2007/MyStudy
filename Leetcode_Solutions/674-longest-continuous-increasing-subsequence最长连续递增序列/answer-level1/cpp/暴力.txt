### 解题思路

### 代码

```cpp
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int length = 1;
        int cnt = 1;
        for(int i = 1 ; i < nums.size() ; ++i)
        {
            if(nums[i] > nums[i - 1])
            {
                cnt++;
                length = max(length, cnt);
            }
            else
            {
                cnt = 1;
            }
        }
        return length;
    }
};
```
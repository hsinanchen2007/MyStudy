### 解题思路
貌似比左闭右闭快那么一丢丢

### 代码

```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while(left + 1 < right)
        {
            int mid = left + (right - left) / 2;
            if(nums[mid] > nums[right])
            {
                left = mid;
            }
            else
                right = mid;
        }
        if(nums[left] < nums[right])
            return nums[left];
        else
            return nums[right];
    }
};
```
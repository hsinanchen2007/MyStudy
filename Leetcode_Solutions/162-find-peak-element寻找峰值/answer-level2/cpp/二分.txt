### 解题思路
如果mid比mid+1小，那么我们起码可以保证mid+1有可能是一个峰值，所以我们到右边搜，如果mid大于等于mid+1，那么我们可以保证mid有可能是一个峰值，所以我们到包括mid在内的左边搜，最关键的是这道题保证了一定有峰值，所以可以这样处理。

### 代码

```cpp
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            if(nums[mid] < nums[mid + 1])
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};
```
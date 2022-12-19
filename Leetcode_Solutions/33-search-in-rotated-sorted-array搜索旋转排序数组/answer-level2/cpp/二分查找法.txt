### 解题思路
思路很简单，二分后总有一半排序过的，如果不是排序的这一半查找就在另外一半查找

### 代码

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        //二分 总有一半排序过 或者非排序过的
        int l = 0;
        int r = nums.size()-1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(nums[mid] == target) return mid;
            bool lp = nums[mid] >= nums[l]; //左边排序过
            if(lp)
            {
                if(nums[mid] > target && nums[l] <= target)
                    r = mid-1;
                else
                    l = mid+1;
            }
            else
            {
                if(nums[mid] < target && nums[r] >= target)
                    l = mid+1;
                else
                    r = mid-1;     
            }
        }
        return -1;
    }
};
```
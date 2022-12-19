先找出有序段

### 代码

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int l = 0;
        int r = nums.size()-1;
        int mid = (l+r)/2;
        while(l<=r)
        {
            mid = (l+r)/2;
            if(target == nums[mid])
            {
                return mid;
            }
            if(nums[mid] < nums[r])
            {
                if(nums[mid]<target&&nums[r]>=target)
                {
                    l = mid+1;
                }
                else
                    r = mid-1;
            }
            else
            {
                if(nums[l]<=target&&nums[mid]>target)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
        }
        return -1;
    }
};
```
### 解题思路
先搜索旋转点，再二分

### 代码

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty())
            return -1;
        if(nums.size() == 1)
        {
            if (target == nums[0])
            {
                return 0;
            }
            else
            {
                return -1;
            }
        }
        int l = 0;
        int r = nums.size()-1;
        while(l < r)
        {
            cout<<l<<" "<<r<<endl;
            int mid = (l + r + 1)/2;
            if(nums[l] == target)
                return l;
            if(nums[r] == target)
                return r;
            if(nums[mid] == target)
                return mid;
            if(mid == r) //说明l+1 = r
            {
                if(nums[l] < nums[r])
                    r = -1;
                else 
                    break;
            }
            if(nums[l] > nums[mid]) //若左边大于中点，说明旋转点在左半边
            {
                r = mid;
            }
            else
            {
                l = mid;
            }
        }
        if(r >= 0)
        {
            int point = r;
            if(target > nums.back() && target >= nums.front() && target <= nums[point - 1])
            {
                l = 0;
                r = point - 1;
            }
            else if(target <= nums.back() && target >= nums[point])
            {
                l = point;
                r = nums.size()-1;
            }
            else
            {
                return -1;
            }
        }
        else
        {
            l = 0;
            r = nums.size()-1;
        }
        
        
        
        while(l < r)
        {
            int mid = (l + r + 1)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
            if(l == r && nums[l] == target)
            {
                return l;
            }
        }
        return -1;
    }
};
```
### 解题思路
由于时间复杂度限制，只能采用二分法，两次二分法，分别找到开始位置和结束位置。

### 代码

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size();
        vector<int> res;
        int left=0,right=len-1;
        while(left<=right)
        {
            if(right==left&&nums[left]!=target)
                break;
            int mid = (left+right)/2;
            if(nums[mid]==target&&mid==0||nums[mid]==target&&nums[mid-1]<target)
            {
                res.push_back(mid);
                break;
            }
            else if(nums[mid]>=target)
                right = mid;
            else
                left = mid+1;
        }
        left=0,right=len-1;
        while(left<=right)
        {
            if(right==left&&nums[left]!=target)
                break;
            int mid = (left+right)/2;
            if(nums[mid]==target&&mid==len-1||nums[mid]==target&&nums[mid+1]>target)
            {
                res.push_back(mid);
                break;
            }
            else if(nums[mid]>target)
                right = mid;
            else
                left = mid+1;
        }
        if(res.empty())
            res.assign(2,-1);
        return res;
    }
};
```
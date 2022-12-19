### 解题思路
减治法

### 代码

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
       int size=nums.size();
       if(size==0)
            return 0;
       int left=0,right=size-1;
       if(target>nums[right])
        return size;

        while(left<right)
        {
            int mid=left+(right-left)/2;
            //如果nums[mid]严格小于target 那么一定不在mid的左边
            if(nums[mid]<target)
            {
                //区间应该是[mid+1,right]
                left=mid+1;
            }
            else if(nums[mid]==target)
            {
                return mid;

            }
            else
            {
                right=mid;
                //区间是[left,mid]
            }
        }
        return left;
    }
};
```
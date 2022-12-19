### 减治法C++
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/0e9d5ed3fcd47fa791c21379b2f019108274acd7e54d0d832be520d97f8e9e02-image.png)

### 代码

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int size=nums.size();
        if(size<=0)
            return 0;
        int left=0;
        int right=size-1;
        while(left<right)
        {
            int mid =left+(right-left)/2;
            
            if(nums[mid]<target)
            {
                //如果mid小,目标位置肯定在右边
                left=mid+1;
            }
            else if(nums[mid]==target)
            {
                return mid;
            }
            else
            {
                //如果mid比target大,目标位置就在左边
                right=mid;
            }
            
        }
        if(target>nums[right])
            return right+1;
        else
            return left;
    }
};
```
### 解题思路
简单的二分法。
![image.png](https://pic.leetcode-cn.com/16ba608ca991436647e66096558d352393ff95127171d86534219aa6999b6770-image.png)

### 代码

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size()==0)
            return 0;
        int low=0,high=nums.size()-1;
        int mid;
        while(low<high-1)
        {
            mid=(low+high)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[mid]>target)
                high=mid-1;
            else if(nums[mid]<target)
                low=mid+1;
        }
        if(nums[low]>=target )
            return low;
        else if (nums[high]>=target )
            return high;
        else return high+1;
    }
};
```
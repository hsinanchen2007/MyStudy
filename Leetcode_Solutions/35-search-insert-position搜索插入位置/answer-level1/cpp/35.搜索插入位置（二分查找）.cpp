### 解题思路
二分查找。

### 代码
```C++```
```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;

        while(left<=right){

            int mid=(left+right+1)>>1; #右中位数

            if(nums[mid]==target) #找到直接返回下标
                return mid;

            if (nums[mid]>target)
                right=mid-1;
            else 
                left=mid+1;       
        }
            return left; #找不到

    }
};
```
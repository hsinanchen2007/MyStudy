暴力法：

```c++
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i;
        for(i=0;i<nums.size();i++){
            if(nums[i]>=target)
                return i;
        }
        return i;
    }
};
```
二分查找：

```c++
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        while(left<=right){
            int mid=(right+left)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
                left=mid+1;
            else
                right=mid-1;
        }
        return left;
    }
};
```
二分查找很简单，用left和right代替下标进行计算，比较mid与target的值，判断目标区间。
需要注意边界情况。
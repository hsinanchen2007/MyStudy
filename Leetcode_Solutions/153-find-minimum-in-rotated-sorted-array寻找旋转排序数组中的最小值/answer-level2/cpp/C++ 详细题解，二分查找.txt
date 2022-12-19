### 思路
通过二分查找不断缩小范围，目标值的要求是小于左右相邻的值
三个重新界定左右边界的条件
1. 右边界小于左边界，且mid位置的值小于右边界，说明最小值在旋转后的数组的右半段。
2. 右边界大于左边界，说明范围内数组由小到大排列，直接收敛r=l。
3. mid位置的值大于右边界，说明最小值在mid值的右边。
```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        if(nums.size() == 1)    return nums[0];
        while(l <= r){
            int mid = l + (r - l) / 2;
            cout << mid << endl;
            if((mid == 0 && nums[mid] < nums[mid + 1]) || (mid == nums.size()-1 && nums[mid] < nums[mid - 1]) || (mid != 0 && mid != nums.size()-1 && nums[mid] < nums[mid-1] && nums[mid] < nums[mid+1]))   return nums[mid];
            if(nums[r] <nums[l] && nums[mid] < nums[r]) r = mid - 1;
            else if(nums[r] > nums[l])  r = l;
            else if(nums[mid] > nums[r])    l = mid + 1;
        }
        return -1;
    }
};
```

### 解题思路
利用二分查找中的左边界查找和右边界查找
### 代码

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);  //初始化答案数组
        if(nums.size() == 0)
        return ans;
        int left = 0, right = nums.size();
        while(left < right)  //寻找target的左边界
        {
            int mid = left +(right-left)/2;
            if(nums[mid] == target) right = mid;
            else if(nums[mid] < target) left = mid + 1;
            else if(nums[mid] > target) right = mid;  
        } 
        if(left < nums.size() && nums[left] == target)  //若数组中没有target，left的值为数组中小于target的最大值的位置，进行判断。若left的值为nums.size()表示数组内的值都比target小
        ans[0] = left;
        left = 0, right = nums.size();
        while(left < right)  //寻找target的右边界
        {
            int mid = left +(right-left)/2;
            if(nums[mid] == target) left = mid + 1;
            else if(nums[mid] > target) right = mid;
            else if(nums[mid] < target) left = mid + 1;
        }
        if(left <= nums.size() && left > 0 && nums[left - 1] == target)  //若数组中没有target，left-1的取值范围是[-1，nums.size()-1]，故先进行判断。
        ans[1] = left - 1;
        return ans;
    }
};
```
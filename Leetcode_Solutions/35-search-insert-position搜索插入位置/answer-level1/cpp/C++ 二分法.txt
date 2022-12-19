### 解题思路
见代码
### 代码

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size() == 0){
            return 0;
        }

        int left = 0;
        int right = nums.size() - 1;
        while(right >= left){
            int mid = (left + right) / 2;
            if(nums[mid] == target) {
                return mid;
            }else if(nums[mid] > target){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return right + 1;
    }
};
```
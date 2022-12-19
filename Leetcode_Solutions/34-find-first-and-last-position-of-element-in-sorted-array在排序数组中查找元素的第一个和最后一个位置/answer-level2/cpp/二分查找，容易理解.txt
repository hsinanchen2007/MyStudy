### 解题思路
时间复杂度要求O(logn),使用二分查找
### 代码

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left <= right){
            int mid = (left + right)/2;
            if(target < nums[mid]) right = mid - 1;  //在左边
            else if(target > nums[mid]) left = mid + 1;    //在右边
            else if(target == nums[mid]) { //在中间，往左右判断取值边缘
                left = mid;
                while(left > 0 && nums[left-1] == target) left--;  //left > 0 防止越界
                right = mid;
                while(right < nums.size() - 1 && nums[right+1] == target) right++;  //同理
                return {left, right};
            }
        }
        return {-1, -1};
    }
};
```
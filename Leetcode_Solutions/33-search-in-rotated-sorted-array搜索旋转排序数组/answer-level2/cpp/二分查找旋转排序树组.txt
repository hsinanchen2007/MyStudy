### 解题思路
主要是判断中间值和最右值的关系，若中间值大于最右值，说明左半段有序，可以判断target是否在左半段中，若不在则在右半段中查找；
同理，若中间值小于最右值，说明右半段有序，先判断target是否在右半段中，若不在则在左半段中查找。

### 代码

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0,right = nums.size()-1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) return mid;
            if(nums[mid] > nums[right]){
                if(target < nums[mid] && target >= nums[left])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else{
                if(target > nums[mid] && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return -1;
    }
};
```
### 解题思路
在33题的基础上，添加了重复元素，例如{2,2,2,3,2}，则在判断nums[left]，nums[mid]，nums[right]大小时无法判断，也就无法判断mid是在那个有序列中了，所以需要对数据去重，当nums[mid]等于nums[right]或nums[left]时，就将right指针向左或left指针向右，去重后的操作与33题相同。时间复杂度最好O(logn)，最坏O(n)。
### 代码

```cpp
class Solution {
public:
    bool search(vector<int>& nums, int target) {
    if(nums.empty()){
        return false;
    }

    int left = 0, right = nums.size() - 1, mid = 0;

    while (left <= right){
        mid = left + (right - left)/2;

        if(nums[mid] == target){
            return true;
        }

        if(nums[mid] == nums[right]){
            right--;
            continue;
        }

        if(nums[mid] == nums[left]){
            left++;
            continue;
        }

        if(left < right){
            if(nums[mid] < nums[right]){
                if(nums[mid] < target && target <= nums[right]){
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }
            } else{
                if(nums[mid] > target && target >= nums[left]){
                    right = mid - 1;
                } else{
                    left = mid + 1;
                }
            }
        }

    }

    return false;
    }
};
```
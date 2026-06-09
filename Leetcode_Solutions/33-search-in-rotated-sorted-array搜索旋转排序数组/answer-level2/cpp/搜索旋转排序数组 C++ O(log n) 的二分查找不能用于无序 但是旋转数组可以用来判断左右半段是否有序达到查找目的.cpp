### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    // O(log n)的二分查找，之前二分查找只是用到了有序数组中，在有旋转的数组中直接应用并不适用。如果中间的数小于最右边的数，则右半段是有序的，若中间数大于最右边数，则左半段是有序的，我们只要在有序的半段里用首尾两个数组来判断目标值是否在这一区域内，这样就可以确定保留哪半边了。
    int search(vector<int>& nums, int target) {
        // l：左下标，r：右下标
        int l = 0, r = nums.size() - 1;
        while(l <= r) {
            int mid = l + (r - l >> 2); 
            if (nums[mid] == target) return mid;
            // 右半边有序
            if (nums[mid] < nums[r])  {
                // 如果目标值在右半边有序数组中，移动l，进入下轮的有序数组二分查找
                if (nums[mid] < target && nums[r] >= target) l = mid + 1;
                // 如果目标值在左半边无序数组中，移动r，进入下轮的无序数组二分查找
                else r = mid - 1;
            }
            // 左半边有序
            else {
                if (nums[l] <= target && nums[mid] > target) r = mid - 1;
                else l = mid + 1;
            }
        }
        return -1;
    }
};


#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while(l <= r) {
        int mid = l + (r - l >> 2); 
        if (nums[mid] == target) return mid;
        if (nums[mid] < nums[r])  {
            if (nums[mid] < target && nums[r] >= target) l = mid + 1;
            else r = mid - 1;
        }
        else {
            if (nums[l] <= target && nums[mid] > target) r = mid - 1;
            else l = mid + 1;
        }
    }
    return -1;
}

int main() {
    vector<int> nums = {4,5,6,7,0,1,2};
    cout << search(nums, 0) << endl;
}



```
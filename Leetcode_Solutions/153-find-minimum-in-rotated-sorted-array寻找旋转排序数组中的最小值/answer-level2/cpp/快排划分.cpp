### 解题思路
使用快排划分操作

### 代码

```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        if(nums[high] >= nums[low]) return nums[low];
        vector<int> num1(nums);
       int pivot = nums[0];
       while(low < high) {
           while(nums[high] <= pivot && low < high)
                --high;
            nums[low] = nums[high];
            while(nums[low] >= pivot && low < high)
                ++low;
            nums[high] = nums[low];
       }
       nums[low] = pivot;
       return num1[low + 1];
    }
};
```
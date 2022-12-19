### 解题思路
二分法

### 代码

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // 二分法
        if(nums.empty()) return 0;
        int len = nums.size();
        int left = 0;
        int right = len - 1;

        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] == mid){
                // 左边已经排好序，只看右边
                left = mid + 1;
            }
            else{
                // 缺少元素在右半部分
                right = mid - 1;
            }
        }

        return left;
    }
};
```
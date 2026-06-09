## 思路
主要思想是查找哪个部分在二分查找中可以丢弃，也就是要找到一段有序的部分，然后确定target在左边还是右边。
### 代码
时间复杂度：O(logn)
```c++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } 
            //左半部分有序
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {//target在这段里
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {//右半部分有序
                if (nums[mid] < target && target <= nums[right]) {//target在这段里
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }            
        }
        return -1;
    }
};
```

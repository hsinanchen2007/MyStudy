### 解题思路
https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/solution/er-fen-cha-zhao-suan-fa-xi-jie-xiang-jie-by-labula/

非常强

### 代码

```cpp
class Solution {
public:
    int findleft(vector<int> nums, int target){
      int left = 0, right = nums.size() - 1;
      while(left <= right){
        int mid = (left + right) / 2;
        if(nums[mid] == target){
          right = mid - 1;
        }else if(nums[mid] < target){
          left = mid + 1;
        }else if(nums[mid] > target){
          right = mid - 1;
        }
      }

      if(left >= nums.size() || nums[left] != target)
        return -1;
      return left;
    }

    int findright(vector<int> nums, int target){
      int left = 0, right = nums.size() - 1;
      while(left <= right){
        int mid = (left + right) / 2;
        if(nums[mid] == target){
          left = mid + 1;
        }else if(nums[mid] < target){
          left = mid + 1;
        }else if(nums[mid] > target){
          right = mid - 1;
        }
      }

      if(right < 0 || nums[right] != target)
        return -1;
      return right;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
      if(nums.size() == 0)  return {-1, -1};

      int left = findleft(nums, target);
      if(left == -1)  return {-1, -1};

      int right = findright(nums, target);
      return {left, right};
    }
};
```
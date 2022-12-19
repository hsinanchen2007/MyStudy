### 解题思路
先用二分法找到旋转数组的最小值下标。
如何找到？
让nums[mid]和nums[right]相比,而不是nums[left].
当然，和nums[left]相比也是可以的，那样找的是最大值。可以看我对本题的[另一个题解](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/solution/xian-yong-er-fen-fa-zhao-dao-decreasede-wei-zhi-za/)。
（有收获请点赞）

### 代码

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 先用二分法找到旋转排序数组的最小值，参考153题。如果这个最小值所在下标就是第二个数组的起始位置，那么就再采用二分法找target就好了
        if(nums.size() == 0) return -1;
        int left = 0, right = nums.size()-1;
        while(left < right){
            int mid = left + (right-left)/2;
            if(nums[mid]<nums[right]){
                right = mid;
            }else{
                left = mid+1;
            }
        }
        int minIndex = left;
        if(left == 0){
            return helper(nums,0,nums.size()-1,target);
        }else{
            if(target<=nums[nums.size()-1]){
                return helper(nums,minIndex,nums.size()-1,target);
            }else{
                return helper(nums,0,minIndex-1,target);
            }
        }
    }
    int helper(vector<int>& nums,int left, int right, int target){
        while(left <right){
            int mid = left +(right-left)/2;
            if(nums[mid] == target) return mid;
            if(nums[mid]<target){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        return nums[left]==target?left:-1;
    }
};
```
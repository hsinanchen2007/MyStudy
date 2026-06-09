### 解题思路
看到这道题首先想到的就是二分法。要写出特殊情况。

结果发现还有个更简单的。直接循环数组找到第一个大于或等于target的数返回，没找到就返回nums.size()。 

### 代码

```cpp
class Solution {
public:
    // 执行用时 :8 ms, 在所有 C++ 提交中击败了63.58% 的用户
    // 内存消耗 :6.7 MB, 在所有 C++ 提交中击败了100.00%的用户
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size()==0) return 0;
        int start = 0, end = nums.size()-1;
        while(start<=end){
            int mid = (end-start)/2+start;
            if(nums[mid]==target||(nums[mid]>target&&((mid>start&&nums[mid-1]<target)||mid==start))) return mid;//若中点值刚好等于target或者中间值大于target且mid==start或者mid-1值小于target  return mid;
            if(nums[mid]<target&&mid==end) return ++mid;//若mid值小于target且mid==end、 return ++mid;
            else if(nums[mid]<target) start = mid+1;
            else if(nums[mid]>target) end = mid-1;
        }
        return 0;
    }


    // 执行用时 :4 ms, 在所有 C++ 提交中击败了95.98% 的用户
    // 内存消耗 :6.7 MB, 在所有 C++ 提交中击败了100.00%的用户
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size()==0) return 0;
        for(int i = 0;i<nums.size();++i){
            if(nums[i]>=target) return i;//直接找大于或等于target的数。
        }
        return nums.size();
    }
};
```
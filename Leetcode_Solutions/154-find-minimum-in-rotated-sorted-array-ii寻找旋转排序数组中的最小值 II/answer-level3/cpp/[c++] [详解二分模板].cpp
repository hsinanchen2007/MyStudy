### 解题思路
相对于[LeetCode153题解](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/solution/c-er-fen-mo-ban-by-codave/),其实只需要把与数组第一个元素相等的数组尾部元素删除干净，即可用和上一题一样的思路来处理。

### 代码
解法一
```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size() - 1;
        if (n < 0) return -1;
        while (n > 0 && nums[n] == nums[0]) n -- ;  //[4,5,6,7,0,1,2,3,4,4,4]
        if (nums[n] >= nums[0]) return nums[0]; //[4,5,6,7,4,4,4]后排数组完全单调的情况，被删完了...
        int l = 0, r = n;
        while (l < r) {
            int mid = l + r >> 1;       // [l, mid], [mid + 1, r]
            if (nums[mid] <= nums[n]) r = mid; //[4,5,6,7,3]所以要取等号
            else l = mid + 1;
        }
        return nums[r];
    }
};
```
解法二

```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size() - 1;
        if (n < 0) return -1;
        while (n > 0 && nums[n] == nums[0]) n -- ;
        if (nums[n] >= nums[0]) return nums[0];
        int l = 0, r = n;
        while (l < r) {
            int mid = l + r >> 1;       
            if (nums[mid] < nums[0]) r = mid;
            else l = mid + 1;
        }
        return nums[r];
    }
};
```
思路是先找旋转点，再二分查找。

```cpp
class Solution {
    int find(const vector<int>& nums, int lo, int hi, int target) {
        int m = -1;
        while (lo <= hi) {
            m = lo + (hi-lo)/2;
            // printf("lo=%d, hi=%d, m=%d, nums[m]=%d\n", lo, hi, m, nums[m]);
            if (target == nums[m]) break;
            else if (target < nums[m]) hi = m-1;
            else lo = m+1;
        }
        // 若有多个相同元素，返回索引值最小的一个
        while (m > 0 && nums[m-1] == nums[m]) --m;
        return lo > hi ? -1 : m;
    }
    int find_seq(const vector<int>& nums) {
        int i = 0;
        while (i < nums.size()-1 && nums[i] <= nums[i+1]) ++i;
        return i < nums.size() - 1 ? i+1 : (nums[i] <= nums[0] ? i : 0);
    }
public:
    int search(vector<int>& arr, int target) {
        if (arr.size() == 0) return -1;

        int lo = 0;
        int hi = arr.size()-1;
        // 找最小元素
        // 考虑情况：[10,1,10,10,10]，因此不能用nums[0]做哨兵
        while (lo < hi) {
            int m = lo + (hi-lo)/2;
            if (arr[m] > arr[hi]) lo = m+1;  
            else if (arr[m] < arr[hi]) hi = m;
            // else --hi;  // 考虑情况：[10,10,10,11,10]，因此不能从右往左靠近
            // else ++lo;  // 考虑情况：[10,1,10,10,10]， 因此不能从左往右靠近
            // 只能顺序查找
            else {
                hi = find_seq(arr);
                break;
            }
        }
        // printf("lo=%d, hi=%d\n", lo, hi);
        
        if (target > arr[0]) {
            // 在前半段
            return find(arr, 0, hi-1, target);
        } else if (target < arr[0]){
            // 在后半段
            return find(arr, hi, arr.size()-1, target);
        } else return 0;
    }
};
```
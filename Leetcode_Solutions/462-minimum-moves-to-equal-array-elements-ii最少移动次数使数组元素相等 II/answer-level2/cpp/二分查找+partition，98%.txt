在想明白了是找中位数后，可以用二分查找加partition函数来快速找到中位数，不需要排序，平均复杂度是O(n).
```c++
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        int mid = nums.size() / 2; //只有一个数的情况，需要附初值。
        while (left < right) {
            mid = partition(nums, left, right);
            if (mid == nums.size() / 2) break;
            if (mid < nums.size() / 2) left = mid + 1; //如果mid在数组左半部分，需要去右边寻找。
            else right = mid;
        }
        int res = 0;
        int median = nums[mid];
        for (int i : nums) res += abs(median - i);
        return res;
    }

    int partition(vector<int>& nums, int start, int end) {
        int mid = (start + end) / 2;
        if (start == end) return start;
        swap(nums[mid], nums[end]);
        int i = start-1;
        for (int j = start; j < end; ++j) {
            if (nums[j] < nums[end]) {
                swap(nums[j], nums[i+1]);
                i++;
            }
        }
        swap(nums[i+1], nums[end]);
        return i + 1; //返回选出来的数所处的位置，通过这个位置判断要到左边还是右边寻找。
    }
};
```
以官方配图为例，就是一个M型，此时找到i，a[i] < a[i+1]；然后再去找到a[j] > a[i]，大于a[i]的最小的那个，交换；最后把i+1开始首尾交换。

以 1 1 5 6 8 7 5 举例，首先找到i-6，a[i] < a[i+1]，此时i+1之后都是递减的。
然后从尾开始，找到a[j] > a[i]，找到了j-7。
然后交换i和j，1 1 5 7 8 6 5.
此时i-7之后依然是递减的，把它变成递增的，首尾交换。 1 1 5 7 5 6 8
完成。


class Solution {
public:
    void nextPermutation(vector<int>& nums) {  // 1 1 5 6 8 7
        if (nums.empty()) return;
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) --i;  // find nums[i] < nums[i + 1] 6 8
        if (i >= 0) {
            int j = nums.size() - 1;
            while (j > i && nums[i] >= nums[j]) --j;  // find nums[j] > nums[i] 6 7
            swap(nums[i], nums[j]);  // 1 1 5 7 8 6
        }
        reverse(nums, i + 1);  // 1 1 5 7 6 8
    }
    
    void reverse(vector<int>& nums, int start) {
        int end = nums.size() - 1;
        while (start < end) {
            swap(nums[start], nums[end]);
            ++start, --end;
        }
    }
    
    void swap(int &x, int &y) {
        int tmp = x;
        x = y;
        y = tmp;
    }
};
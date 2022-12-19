执行用时 :4 ms, 在所有 C++ 提交中击败了99.90%的用户
内存消耗 :8.7 MB, 在所有 C++ 提交中击败了79.91%的用户

```
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1) {
            return;
        }
        int s = nums.size();
        int i = s-1;
        int temp;
        while (i > 0 && nums[i] <= nums[i-1]) {
            i--;
        }
        if (i == 0) {
            // 返回升序序列
            for (int k = 0; k < s/2; k++) {
                temp = nums[k];
                nums[k] = nums[s-k-1];
                nums[s-k-1] = temp;
            }
            return;
        }
        // 交换i和i之后比i-1大的最小数，然后将i之后的升序排列
        int j = i;
        while (j < s && nums[i-1] < nums[j]) {
            j++;
        }
        j--;
        temp = nums[i-1];
        nums[i-1] = nums[j];
        nums[j] = temp;
        
        for (int k = 0; k < (s-i)/2; k++) {
            temp = nums[s-k-1];
            nums[s-k-1] = nums[i+k];
            nums[i+k] = temp;
        }
    }
};
```

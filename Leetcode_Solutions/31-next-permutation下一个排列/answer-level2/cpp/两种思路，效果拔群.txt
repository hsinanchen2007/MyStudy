```
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // 思路一：从右往左，右边正序排列，当前值如果大于等于右边最大值，将当前值加入右侧排列，
        //       如果小于右边最大值，则当前值和右边第一个大于当前值的位置互换。
        // 思路二：从右往左找到第一个左边小于右边的数，将左边的数与右边倒序排列的数组中大于该值最小的数进行交换，反转右侧的数组

        //思路二
        if (nums.size() < 2)
            return;

        int start = 0;
        int end = nums.size() - 1;
        int right = nums.size() - 1;
        while (right > 0) {
            if (nums[right-1] < nums[right]) {  // find the first left value is less than right
                start = right;   // change start
                int i = right;
                while (i < nums.size() && nums[right-1] < nums[i])
                    i++;
                int tmp = nums[right-1];
                nums[right-1] = nums[i-1];
                nums[i-1] = tmp;
                break;
            }
            right--;
        }

        // reverse vector from start to end.
        for (int j = 0; j <= (end-start)/2; j++) {
            int tmp = nums[start+j];
            nums[start+j]= nums[end-j];
            nums[end-j] = tmp;
        }

        //思路一
        //if (nums.size() < 2)
        //    return;
//
        //for (int i = nums.size() - 2; i >= 0; i--) {  // i: 当前值；
        //    if (nums[i] >= nums[nums.size()-1]) {  //当前值如果大于等于右边最大值，将当前值加入右侧排列， 
        //        for (int j = i; j < nums.size() - 1; j++) {
        //            int tmp = nums[j];
        //            nums[j] = nums[j+1];
        //            nums[j+1] = tmp;
        //        }
        //    } else if (nums[i] < nums[nums.size()-1]) {  //如果小于右边最大值，则当前值和右边第一个大于当前值的位置互换。
        //        for (int j = i+1; j < nums.size(); j++) {
        //            if (nums[i] < nums[j]) {
        //                int tmp = nums[i];
        //                nums[i] = nums[j];
        //                nums[j] = tmp;
        //                return;
        //            }
        //        }
        //    }
        //}
    }
};
```

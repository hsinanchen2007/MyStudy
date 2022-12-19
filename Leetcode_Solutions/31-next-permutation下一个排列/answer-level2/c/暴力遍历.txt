### 解题思路
此处撰写解题思路
暴力遍历
### 代码

```cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        int ret = len - 1;
        int ret1 = len - 1;
        int temp = 0; 
        int m = 0;
        for (int i = ret; i > 0; i--) {
            if (nums[i] > nums[i - 1]) {
                ret = i - 1;
                break;
            }
        }
        if (ret != len - 1) {
            for (int j = len -1; j > 0; j--) {
                if (nums[j] > nums[ret]) {
                    temp = nums[ret];
                    nums[ret] = nums[j];
                    nums[j] = temp;
                    break;
                }
            }
            m = (len - 1 - ret) / 2;
            for (int n = ret + 1; n < m + ret + 1; n++) {
                temp = nums[n];
                nums[n] = nums[ret1];
                nums[ret1--] = temp;
            }
        } else {
            for (int n = 0; n < len / 2; n++) {
                temp = nums[n];
                nums[n] = nums[ret1];
                nums[ret1] = temp;
                ret1--;
            }
        }
    }
};
```
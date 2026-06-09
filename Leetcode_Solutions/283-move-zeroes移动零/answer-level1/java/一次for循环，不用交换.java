1. `lastNonZeroIndex`指向从前向后最后一个不为0的元素，`i`为遍历指针。
```
 class Solution {
        public void moveZeroes(int[] nums) {
            //定义 nums[0]~nums[lastNonZeroIndex]!=0
            int lastNonZeroIndex = -1;
            for (int i = 0; i < nums.length; i++) {
                if (nums[i] != 0) {
                    nums[++lastNonZeroIndex] = nums[i];
                    //避免原地覆盖
                    if (i != lastNonZeroIndex) {
                        nums[i] = 0;
                    }
                }
            }
        }
    }
```

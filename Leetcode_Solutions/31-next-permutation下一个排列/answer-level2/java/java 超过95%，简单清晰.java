思路：
1、从后往前找，当找到i使得nums[i] > nums[i - 1]的时候，则需要将[i-1, nums.length)的数进行重排序
2、重排序规则：从i-1后面找到第一个大于nums[i - 1]的数，并与nums[i - 1]交换，之后将[i, nums.length - 1)进行字典序排序（直接调用Arrays.sort()即可）

```
import java.util.Arrays;

class Solution {
    public void nextPermutation(int[] nums) {
        if ((nums == null) || (nums.length == 0)) {
            return;
        }

        for (int i = nums.length - 1; i >= 0; i--) {
            int pre = (i == 0) ? Integer.MIN_VALUE : nums[i - 1];
            if (nums[i] > pre) {
                // 如果找到头了, 说明是原序列是字典序最大的, 直接sort即可
                if (i == 0) {
                    Arrays.sort(nums);
                    return;
                }

                // 将i-1后面第一个大于nums[i]的数找出来并与之调换
                for (int j = nums.length - 1; j >= i; j--) {
                    if (nums[j] > pre) {
                        int tmp = nums[j];
                        nums[j] = nums[i - 1];
                        nums[i - 1] = tmp;
                        break;
                    }
                }
                
                // 将i后面的数字进行字典序升序排列
                Arrays.sort(nums, i, nums.length);
                return;
            }
        }
    }
}
```

![image.png](https://pic.leetcode-cn.com/45fa726a925077f3083aee2537ff5237ffa9b396ef77dd24b360ec210990b5ae-image.png)

```
class Solution {
    public void nextPermutation(int[] nums) {
        if(nums == null || nums.length < 2) return; // 特殊情况处理

        // 1、找到i，从i开始先升后降，只需要关注i及以后的元素
        int i = nums.length - 2;
        int t1 = nums[nums.length - 1];
        for(;i > -1;i--) {
            if(nums[i] < t1) {
                break;
            }
            t1 = nums[i];
        }

        // 2、如果找到了i，替换 i 和 i之后比i大的最小值，注意：这时候我们得到的结果中i（不包括i）以后的元素降序排列
        if (i > -1) {
            t1 = i + 1;
            int j = i + 2;
            for(;j < nums.length && t1 < nums.length;j++) {
                if (nums[j] <= nums[t1] && nums[j] > nums[i]) {
                    t1 = j;
                }
            }

            j = nums[i];
            nums[i] = nums[t1];
            nums[t1] = j;
        }

        // i（不包括i）以后的元素反序
        int l = i + 1;
        int r = nums.length - 1;
        while(l < r) {
            i = nums[l];
            nums[l] = nums[r];
            nums[r] = i;
            l++;r--;
        }
    }
}

```
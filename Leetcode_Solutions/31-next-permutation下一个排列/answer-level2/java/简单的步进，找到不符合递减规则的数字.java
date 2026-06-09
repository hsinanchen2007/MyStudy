### 解题思路
从右往左步进，找到第一个不符合递减规则的位置，和比当前数略大的数字的位置交换，然后此位置的右边调换顺序。

### 代码

```java
class Solution {
     public void nextPermutation(int[] nums) {
        for (int i = nums.length - 2; i >= 0; i--) {
            int a = nums[i];
            for (int j = nums.length - 1; j > i; j--) {
                int b = nums[j];
                if (b > a) {
                    nums[i] = b;
                    nums[j] = a;
                    change(nums, i + 1);
                    return;
                }
            }
        }
        change(nums, 0);
    }

    private void change(int[] nums, int index) {
        for (int i = index; i < (nums.length + index) / 2; i++) {
            int j = nums.length + index - i - 1;
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        }
    }
}
```
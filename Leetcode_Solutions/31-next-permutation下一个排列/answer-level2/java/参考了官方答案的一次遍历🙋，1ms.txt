
执行用时 :1 ms, 在所有 java 提交中击败了100.00%的用户
内存消耗 :36.5 MB, 在所有 java 提交中击败了90.15%的用户
```
class Solution {
    public void nextPermutation(int[] nums) {
        // 从右到左查找
        int i = nums.length-2;
        while (i >= 0) {
            if (nums[i] < nums[i + 1]) {
                int j = nums.length-1;
                while (j > i) {
                    if (nums[i] < nums[j]) {
                        // 交换两数
                        swap(nums, i, j);
                        // 反转i后面的元素
                        revert(nums, i+1, nums.length-1);
                        break;
                    }
                    j--;
                }
                return;
            }
            i--;
        }
        // 到这里就确认nums是倒序排序的数列了，把他翻转
        revert(nums, 0, nums.length-1);
    }

    private void revert(int[] nums, int from, int to) {
        while (from < to) {
            swap(nums, from, to);
            from++;
            to--;
        }
    }

    private void swap(int[] nums, int from, int to) {
        int temp = nums[from];
        nums[from] = nums[to];
        nums[to] = temp;
    }
}
```

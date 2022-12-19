i和j上同时是1就比不了了，于是在快排中加了打破1-1的处理，刚写的时候没考虑到1-1。
复杂度可以认为是O(n)吗？
```
class Solution {
    public void sortColors(int[] nums) {
        if (nums.length < 2) {
            return;
        }
        int i = 0, j = nums.length - 1;
        while (true) {
            while (i < j && nums[i] == 0) {
                i++;
            }
            while (j > i && nums[j] == 2) {
                j--;
            }
            if (nums[i] == 1 && nums[j] == 1) {
                int a = i;
                while (a < nums.length && nums[a] == 1) {
                    a++;
                }
                if (a > nums.length - 1 || a >= j) {
                    break;
                } else {
                    if (nums[a] == 0) {
                        swap(nums, i++, a);
                    } else {
                        swap(nums, j--, a);
                    }
                }
            }
            if (i >= j) {
                break;
            }
            swap(nums, i, j);
        }
    }

    public void swap(int[] arr, int i, int j) {
        int temp;
        temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
    }
}
```

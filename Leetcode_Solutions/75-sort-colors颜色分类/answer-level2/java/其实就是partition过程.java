```java
    public void sortColors(int[] nums) {
        int num = 1;
        int small = -1, equal = 0, big = nums.length;
        while (equal < big) {
            if (nums[equal] < num) {
                swap(nums, ++small, equal++);
            } else if (nums[equal] == num) {
                equal++;
            } else {
                swap(nums, --big, equal);
            }
        }
    }

    private void swap(int[] nums, int p1, int p2) {
        if (p1 != p2) {
            nums[p1] = nums[p1] ^ nums[p2];
            nums[p2] = nums[p1] ^ nums[p2];
            nums[p1] = nums[p1] ^ nums[p2];
        }
    }
```
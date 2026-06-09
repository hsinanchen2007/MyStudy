

```
    public void sortColors(int[] nums) {
        if (nums == null || nums.length <= 1) {
            return;
        }
        int n = nums.length;
        // p0表示0的右边界，小于p0的都比0小； p2表示2的左边界，大于p2的都比2大；
        // cur表示当前位置， 如果nums[cur] == 0则与p0交换，cur++, p0++;  如果nums[cur]==2则与p2交换， p2--
        int p0 = 0, p2 = n - 1, cur = 0;
        while (cur <= p2) {
            if (nums[cur] == 0) {
                swap(nums, cur, p0);
                cur++;
                p0++;
            } else if (nums[cur] == 2) {
                swap(nums, cur, p2);
                p2--;
            } else {
                cur++;
            }
        }        
    }
    private void swap(int[] nums, int a, int b) {
        int tmp = nums[a];
        nums[a] = nums[b];
        nums[b] = tmp;
    }
```
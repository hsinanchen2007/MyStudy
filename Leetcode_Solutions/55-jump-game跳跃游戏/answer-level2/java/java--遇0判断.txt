从后向前找，查看是否有0，如果有0，则需要判断是否有能跳到last节点的位置

```
    public boolean canJump(int[] nums) {
        if (nums == null || nums.length == 0) {
            return false;
        }
        int last = nums.length - 1;
        for (int i = nums.length - 2; i >= 0; i--) {            
            while (i >= 0 && nums[i] == 0) {
                i--;
            }
            while (i >= 0 && nums[i] + i < last) {
                i--;
            }
            last = i;
        }
        return last == 0;
    }
```
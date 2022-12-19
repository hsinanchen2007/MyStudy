第一次发题解，觉得觉得快慢指针也是可以做的，效率略微低点，还望大家指正，闲话不多说，上代码：

public int findDuplicate(int[] nums) {
        if (nums == null || nums.length == 0) {
            return -1;
        }

        int slow = 0;
        int fast = slow + 1;
        while (slow < fast) {
            if (fast < nums.length) {
                if (nums[slow] == nums[fast]) {
                    return nums[slow];
                }
                fast++;
            } else {
                if (slow >= nums.length - 1) {
                    break;
                } else {
                    slow++;
                    fast = slow + 1;
                }
            }
        }

        return -1;
    }
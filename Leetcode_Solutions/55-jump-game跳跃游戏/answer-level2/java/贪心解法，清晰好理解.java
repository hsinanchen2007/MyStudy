```
 public static boolean canJump(int[] nums) {
        int max = 0;
        for (int i = 0; i < nums.length; i++) {

            //如果目前能到达的最大距离比i还小，则肯定跳不到i这个位置，即达不到终点，返回false.
            if (max < i) return false;
            /**
             * 若能跳到i这个位置，则我们有机会更新最大可达距离：
             *
             * 1.nums[i] + i 代表从i这个位置起跳能达到的最远距离
             * 2.max 代表从i前面的某个位置起跳能达到的最远距离
             * 二者选较大的那个作为新的最远可到达距离
             */
            max = Math.max(nums[i] + i, max);
        }
        //能到达这一步，说明max>=nums.length.
        return true;
    }
```

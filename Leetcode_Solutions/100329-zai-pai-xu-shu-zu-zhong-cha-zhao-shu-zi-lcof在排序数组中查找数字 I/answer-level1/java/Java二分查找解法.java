```Java
    public int search(int[] nums, int target) {
        if (nums == null || nums.length == 0) return 0;
        int[] ret = new int[]{-1,-1};
        int l = 0, r = nums.length;
        int m;
        // 找最左边的位置
        while (l < r) {
            m = l + (r -l) / 2;
            if (nums[m] < target) l = m + 1;
            else r = m;
        }
        // 获得的 l 表示：第一个满足 nums[l] < target 的元素下标，所以要考虑到下标的越界问题
        if (l < nums.length && nums[l] == target) ret[0] = l;
        // 找右边的位置
        l = 0;
        r = nums.length;
        while (l < r) {
            m = l + (r -l) / 2;
            if (nums[m] <= target) l = m + 1;
            else r = m;
        }
        // 如何使用多的的边界值 l, 在二分查找算法中至关重要
        if (l == 0 && nums[l] == target) ret[1] = 0;
        else if (l > 0 && nums[l-1] == target) ret[1] = l-1;
        if(ret[1] == -1 || ret[0] == -1) return 0;
        return ret[1]-ret[0]+1;
    }
```
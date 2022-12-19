比33题只是多了两个判断，因为允许重复，判断mid左侧右侧是否单调前，增加判断和左右边界是否相等，相等的话收缩边界more again喽。
```
    /**
     * 执行用时 :1 ms, 99.69%
     * 内存消耗 :38.4 MB, 36.61%
     */
    public boolean search(int[] nums, int target) {
        int start = 0;
        int end = nums.length - 1;
        int mid;
        while (start <= end) {
            mid = (end + start) / 2;
            if (nums[mid] == target)
                return true;
            /* 比33题多的 begin */
            if (nums[mid] == nums[start]) {  //KEYPOINT
                start++;
                continue;
            } else if (nums[mid] == nums[end]) {  //KEYPOINT
                end--;
                continue;
            }
            /* 比33题多的 end */
            if (nums[end] > nums[mid]) // mid右侧单调递增
                if (nums[mid] < target && target <= nums[end]) //在单调递增区间内
                    start = mid + 1;
                else
                    end = mid - 1;
            else { // mid左侧单调递增
                if (nums[start] <= target && target <= nums[mid]) //在单调递增区间内
                    end = mid - 1;
                else
                    start = mid + 1;
            }
        }
        return false;
    }
```

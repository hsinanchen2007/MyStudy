public int searchInsert(int[] nums, int target) {
            int location = Arrays.binarySearch(nums, target);
            if (location < 0) {
                return Math.abs(location) - 1;
            } else {
                return location;
            }
        }
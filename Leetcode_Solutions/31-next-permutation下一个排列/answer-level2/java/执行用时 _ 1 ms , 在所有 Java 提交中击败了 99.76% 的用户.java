public void nextPermutation(int[] nums) {
        int length = nums.length;
        boolean isExist = false;
        for (int i = length - 1; i > 0; i--) {
            if (nums[i - 1] < nums[i]) {
                int[] sortNums = new int[length - i];
                System.arraycopy(nums, i, sortNums, 0, length - i);
                Arrays.sort(sortNums);
                for (int m = 0; m < sortNums.length; m++) {
                    if (sortNums[m] > nums[i - 1]) {
                        int tempInt = nums[i - 1];
                        nums[i - 1] = sortNums[m];
                        sortNums[m] = tempInt;
                        Arrays.sort(sortNums);
                        break;
                    }
                }
                System.arraycopy(sortNums, 0, nums, i, length - i);
                isExist = true;
                break;
            }
        }

        if (!isExist) {
            Arrays.sort(nums);
        }
    }
    Arrays.sort(nums);
    List<List<Integer>> resultList = new ArrayList<>();
    int length = nums.length;
    if (length < 3) return resultList;

    for (int i = 0; i < length - 2; i++) {
        if (i > 0 && nums[i] == nums[i-1]) continue;
        int start = nums[i];
        int left = i + 1;
        int right = length - 1; 
        while(left < right) {
            while (left < right && start + nums[left] + nums[right] < 0) {
                //if (nums[left] == nums[left - 1]) break;
                left++;
            }
            while (left < right && start + nums[left] + nums[right] > 0) {
                right--;
            }
            while (left < right && start + nums[left] + nums[right] == 0) {
                resultList.add(Arrays.asList(start, nums[left], nums[right]));
                do {
                    left++;
                }
                while (nums[left - 1] == nums[left] && left < right);
            }
        }
    }
    return resultList;
    public List<String> summaryRanges(int[] nums) {
        List<String> list = new ArrayList<>();
        int count = 0;
        for (int i = 0; i < nums.length; i++) {
            if (i + 1 < nums.length && nums[i + 1] - nums[i] == 1) {
                count++;
            } else {
                if (count == 0) {
                    list.add(String.valueOf(nums[i]));
                } else {
                    list.add(String.valueOf(nums[i - count]) + "->" + String.valueOf(nums[i]));
                }
                count = 0;
            }
        }
        return list;
    }
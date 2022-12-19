    public int[] decompressRLElist(int[] nums) {
        if (nums == null) {
            return new int[0];
        }

        List<Integer> list = new ArrayList<>();
        int n = nums.length;
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < nums[2 * i]; j++) {
                list.add(nums[2 * i + 1]);
            }
        }

        return list.stream().mapToInt(Integer::valueOf).toArray();
    }
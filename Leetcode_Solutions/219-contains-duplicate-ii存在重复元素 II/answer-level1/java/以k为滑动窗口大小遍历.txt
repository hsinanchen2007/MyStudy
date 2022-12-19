    
    public static boolean containsNearbyDuplicate(int[] nums, int k) {
		if(k < 1) {
			return false;
		}
		HashSet<Integer> hs = new HashSet<>();
		int left = 0;
		int right = left + k;
		for(int i = 0;i < nums.length && i <= right;i++) {
			if(hs.contains(nums[i])) {
				return true;
			}
			hs.add(nums[i]);
		}
		for(int i = right + 1;i < nums.length;i++) {
			hs.remove(nums[left++]);
			if(hs.contains(nums[i])) {
				return true;
			}
			hs.add(nums[i]);
		}
		return false;
	}
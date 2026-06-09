    class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
		Arrays.sort(nums);
		List<List<Integer>> list = new ArrayList<>();
		int n = nums.length;
		for(int i = 0; i <= n - 4; i = nextIndex(nums, i)) {
			for(int j = i + 1; j <= n - 3; j = nextIndex(nums, j)) {
				int t = target - nums[i] - nums[j];
				if(nums[j + 1] + nums[j + 2] > t || nums[n - 1] + nums[n - 2] < t) {
					//注意体会上面这个条件的意味
					continue;
				}
				int third = j + 1;
				int fourth = n - 1;
				if(third >= fourth) {
					break;
				}
				while(third < fourth) {	//寻找第三个和第四个数
					if(nums[third] + nums[fourth] == t) {
						list.add(Arrays.asList(nums[i], nums[j], nums[third], nums[fourth]));
						third = nextIndex(nums, third);
						fourth = preIndex(nums, fourth);
					}else if(nums[third] + nums[fourth] < t) {
						third = nextIndex(nums, third);
					}else {
						fourth = preIndex(nums, fourth);
					}			
				}
			}
		}
		return list;
    }
	//私有方法
	private int nextIndex(int[] nums, int index) {
		for(int cur = index + 1; cur < nums.length; cur ++) {
			if(nums[cur] != nums[index]) {
				return cur;
			}
		}
		return nums.length;
	}
	private int preIndex(int[] nums, int index) {
		for(int cur = index - 1; cur >= 0; cur --) {
			if(nums[cur] != nums[index]) {
				return cur;
			}
		}
		return -1;
	}
}
public static List<Integer> findDisappearedNumbers(int[] nums) {
		int elem;
		//遍历数组中的元素
		for (int i = 0; i < nums.length; i++) {
			//用数组中的每个数去减去一然后赋值给elem来控制数组的下标
			elem = nums[i] - 1;
			//判断elem的值是不是小于零
			while (elem < 0) {
				//这句是为了防止数组中有负数存在
				elem += nums.length;
			}
			//因为数组中的元素是连续的所以找到新数组的下标用
			//原来给位置的元素减去数组长度再赋给新数组中的当前位置
			nums[elem] = nums[elem] - nums.length;
		}
		
		List<Integer> ans = new ArrayList<>();
		for (int j = 0; j < nums.length; j++) {
			//然后再遍历数组此时的数组中只有缺失的元素减一的位置的元素是正的
			if (nums[j] > 0) {
				ans.add(j + 1);
			}
		}
		return ans;
	}
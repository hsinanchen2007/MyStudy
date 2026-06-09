public static int findPairs(int[] nums, int k) {
	//思路：利用map集合的没有重复元素和存放的是两个有关联的k和value
	//的值得特性只要符合条件就添加，map集合添加时会把相同的给替换掉
	 if(k < 0) {
		 return 0;
	 }
	 //先给数组排序保证是用大的减去小的
	 Arrays.sort(nums);
	 //然后创建map集合
		HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
		//遍历数组中的元素
		for (int i = 0; i < nums.length; i++) {
			for (int j = i+1; j < nums.length; j++) {
				//只要符合条件的就往map集合中添加
				if (nums[j]-nums[i]==k) {
					map.put(nums[j], nums[i]);
				}
			}
		}
		//最后输出map集合的大小就是符合条件的个数
	        return map.size();
	    }
	}
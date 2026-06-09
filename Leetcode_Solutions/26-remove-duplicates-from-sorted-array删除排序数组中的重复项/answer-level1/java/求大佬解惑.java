public int removeDuplicates(int[] nums) {
	if (nums.length == 0)
		return 0;

	 int i = 0;
	 int j = 1;
	 List<Integer> list1 = new ArrayList<Integer>();
	 while(i < nums.length && j < nums.length){
		 if (nums[i] != nums[j]){
			 list1.add(i);
			 i = j;
			 j++;
		 }else {
			 j++;
		 }
	 }
	list1.add(i);

	return list1.size();
}


我这个代码也是输出正确的，但是leetcode提交错误，为什么呢？
	/*
	 * 思路：先经得到n-1个元素的全部子集共2^(n-1)个，在前述2^(n-1)个子集中，分别加入第n个元素构造出包含第n个元素的所有子集
	 * 将n-1个元素的全部子集和所有包含第n个元素的所有子集合并，得到包含n个元素的全部子集。
	 * 例如：numsOne = {1}  的全部子集为{{}，{1}}，
	 * 那么numsTwo={1,2} 的构造过程为,由{{}，{1}}合并{{2},{1,2}} (通过{}中加入2得到{2},{1}中加入2得到{1,2})
	 * 得到其全部子集为{{},{1},{2},{1,2}}
	 */
	public List<List<Integer>> backtrack(int[] nums, int n){
		List<List<Integer>> result = new ArrayList<>();
		if(n==0) {
			List<Integer> tempList = new ArrayList<>();
			result.add(tempList);
		}else {
			List<List<Integer>> subResult = backtrack(nums,n-1);
			List<List<Integer>> addNResult = new ArrayList<>();
			for(List<Integer> oneSubset:subResult) {
				List<Integer> tempList = new ArrayList<>();
				tempList.addAll(oneSubset);
				tempList.add(nums[n-1]);
				addNResult.add(tempList);
			}
			result.addAll(subResult);
			result.addAll(addNResult);
		}
		return result;
	}
	
    public List<List<Integer>> subsets(int[] nums) {
    	List<List<Integer>> result = new ArrayList<>();
    	result = backtrack(nums, nums.length);	                                                                                                                                                                                                                                                                                             
    	return result;
    }
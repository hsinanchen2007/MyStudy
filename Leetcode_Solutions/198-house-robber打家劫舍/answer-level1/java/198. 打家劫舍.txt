/**
	 * 假设说我在中间的某一个房间i，我要想获得最大利润，有两个选择，
	 * 1.该房间i的金额加上i-2房间的钱
	 * 2.不取该房间的钱，直接取i-1房间的钱
	 * 最大利润就是这两个选择之间的最大值。
	 * @param nums
	 * @return
	 */
    public int rob(int[] nums) {
    	// 如果数组长度为0 
    	if(nums.length==0) return 0;
       // 如果数组长度为1，直接返回
    	if(nums.length==1) return nums[0];
    	// 如果数组长度为2，返回最大值
    	if(nums.length==2) return nums[0]>nums[1] ? nums[0]:nums[1];
    	// 存储每个房间的利润
    	int[] profit = new int[nums.length];
    	profit[0] = nums[0];
    	profit[1] = nums[0]>nums[1] ? nums[0]:nums[1];
    	for(int i=2;i<nums.length;i++){
    		profit[i] = profit[i-1]>profit[i-2]+nums[i] ? profit[i-1] : profit[i-2]+nums[i];
    	}
    	return profit[profit.length-1];
    }
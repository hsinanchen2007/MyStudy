int maximumProduct(vector<int>& nums) {
	int len = nums.size();
	//if (len == 3) return nums[0] * nums[1] * nums[2];
	sort(nums.begin(), nums.end());
	return max(nums[len - 1] * nums[len - 2] * nums[len - 3], nums[len - 1] * nums[0] * nums[1]);
}
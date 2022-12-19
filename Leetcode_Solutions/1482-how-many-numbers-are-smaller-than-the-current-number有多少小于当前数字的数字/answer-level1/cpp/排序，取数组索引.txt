std::vector<int> smallerNumbersThanCurrent(std::vector<int>& nums) {
	std::vector<int> res(nums.size());
	std::copy(nums.begin(), nums.end(), res.begin());
	std::sort(nums.begin(), nums.end());            //排序
	for (size_t i = 0; i < nums.size(); ++i) {      //取排序后数组的索引
		res[i] = find(nums.begin(), nums.end(), res[i]) - nums.begin();
	}
	return res;
}
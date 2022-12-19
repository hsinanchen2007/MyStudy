 class Solution {
 public:
	 void rotate(vector<int>& nums, int k) {
		 int len = nums.size();
		 k = k%nums.size();
		 nums.insert(nums.begin(), nums.end()-k,nums.end());
		 nums.erase(nums.begin() + len, nums.end());	 
	 }
 };
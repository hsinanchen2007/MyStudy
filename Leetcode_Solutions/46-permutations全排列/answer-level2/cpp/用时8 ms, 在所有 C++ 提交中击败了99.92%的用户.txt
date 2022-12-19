不创建新字符串，只依靠交换字符位置节省时间

```c++
class Solution {
public:

	vector<vector<int>> ans;
	int len;
	vector<int> nums;
	vector<vector<int>> permute(vector<int>& nums) {
		this->len = nums.size();
		this->nums = nums;

		Recursive(0);
		return this->ans;
	}

	void Recursive(int deep) {
		if (deep == len-1) {
			ans.push_back(nums);
		}
		
		for (int i = deep; i < len; i++) {
			//交换
			int t = nums[i]; 
			nums[i] = nums[deep];
			nums[deep] = t;

			Recursive(deep+1);

			//交换回来
			nums[deep] = nums[i];
			nums[i] = t;

		}

	}
};
```

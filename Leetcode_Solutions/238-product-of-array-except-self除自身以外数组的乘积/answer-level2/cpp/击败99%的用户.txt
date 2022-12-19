```
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
	int curAccProduct = 1;
	vector<int> result;
	for (int i = 0; i < nums.size(); i++)
	{
		result.push_back(curAccProduct);
		curAccProduct *= nums[i];
	}
	curAccProduct = 1;
	for (int i = nums.size()-1; i >= 0; i--)
	{
		result[i] *= curAccProduct;
		curAccProduct *= nums[i];
	}
	return result;
}
};
```

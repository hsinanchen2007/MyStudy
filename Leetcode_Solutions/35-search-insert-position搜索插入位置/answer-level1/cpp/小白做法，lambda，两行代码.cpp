```
int searchInsert(vector<int>& nums, int target) 
{
	auto f = find_if(nums.begin(), nums.end(),[=](const int a){ return a >= target; });
	return f - nums.begin();
}
```
击败97%

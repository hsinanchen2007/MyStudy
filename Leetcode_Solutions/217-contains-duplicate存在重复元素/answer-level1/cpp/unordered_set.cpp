

### 代码

```cpp
class Solution {
public:
	bool containsDuplicate(vector<int>& nums)
	{
		unordered_set<int> myset;
		for (int i = 0; i < nums.size(); i++)
			myset.insert(nums[i]);
		if (myset.size() != nums.size())
			return true;
		else
			return false;
	}
};
```
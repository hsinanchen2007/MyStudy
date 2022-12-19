执行用时 :44 ms, 在所有 C++ 提交中击败了59.90%的用户
内存消耗 :17.3 MB, 在所有 C++ 提交中击败了20.37%的用户

### 代码

```cpp
using namespace std;
class Solution {
public:
	bool containsDuplicate(vector<int>& nums) 
	{
		if (nums.size() == 0) return false;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size()-1; ++i)
		{
			if (nums[i] == nums[i + 1])
				return true;
			
		}
		return false;
	}
};
```
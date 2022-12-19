### 解题思路
初来驾到，，想了半天

### 代码

```cpp
class Solution
{
public:
	vector<int> twoSum(vector<int> &nums, int target)
	{
		vector<int> res;
		int gs = int(nums.size());
		for (auto calc = 0; calc < gs; calc++) {
			int calc2 = calc+(gs-calc);
			//cout << calc << "," << calc2 << endl;
			for (int y = 0; y < calc2; y++) {
				if (y != calc) {
					int jg = nums[calc] + nums[y];
					if (jg == target) {
						res.push_back(calc);
						res.push_back(y);
						return res;
					}
				}
			}
		}
		return{};
	}
};
```
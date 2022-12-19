### 解题思路
转换成字符串，重新排序，比较两字符串正反加之和作为仿函数

### 代码

```cpp
class Solution {
public:
	string largestNumber(vector<int>& nums) {
		string res = "";
		sort(nums.begin(), nums.end(), [](int a, int b) {
			string sa = to_string(a), sb = to_string(b);
			return sa + sb > sb + sa;
		});
		if(!nums.empty() && nums[0] == 0)return "0";
		for (auto n : nums) {
			res += to_string(n);
		}
		return res;
	}
};
```
### 解题思路
第一步，将所有输入转为字符串。
第二步，将字符串排个序，头n（n为较短字符串的长度）位相同的，对比一下它们各自在前面时的组合哪个更大。
第三步，将字符串依次加入res中
搞定。简单易懂。

### 代码

```cpp
bool cmp(const string& a, const string& b)
{
	size_t s = min(a.size(), b.size());
	if (a.substr(0, s) != b.substr(0, s))
		return a > b;
	return a + b > b + a;
}

class Solution {
public:
	string largestNumber(vector<int>& nums) {
		vector<string> snums(nums.size());
		for (int i = 0; i < nums.size(); i++)
		{
			snums[i] = to_string(nums[i]);
		}
		sort(snums.begin(), snums.end(), cmp);
		string res = "";
		for (int i = 0; i < snums.size(); i++)
			res += snums[i];
		if (res[0] == '0')
			return "0";
		return res;
	}
};
```
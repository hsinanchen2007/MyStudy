### 解题思路
提前存储数字对应的字母 用空间换时间
将当前字符对应的字母分别于之前所有的串相加

### 代码

```cpp
class Solution {
public:
    vector<string> letterCombinations(string digits) {
	vector<string> ans;
	int len = digits.length();
	if (len == 0) return ans;
	ans = { "" };
	string a[] = { " ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
	for (int i = 0; i < len; i++)
	{
		vector<string> temp;
		for (int k = 0; k < ans.size(); k++)
		for (int j = 0; j < a[digits[i] - '0'].size(); j++) {
			temp.push_back(ans[k]+a[digits[i] - '0'][j]);
		}
		ans = temp;
	}
	return ans;
    }
};
```
### 解题思路
比较简单的操作
利用istringstream 读取到vector中
逆序输出到string中
### 代码

```cpp
class Solution {
public:
	string reverseWords(string str) {
		istringstream scin(str);
		string tmp;
		vector<string> vec;
		while (scin >> tmp) {
			vec.push_back(tmp);
		}
		string ans;
		for (int i = vec.size() - 1; i >= 0; i--) {
			if (i != vec.size() - 1) {
				ans += " ";
			}
			ans += vec[i];
		}
		return ans;
	}
};

```
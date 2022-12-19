同一组的元素是排序后相等的字符串。
下面代码用了两个vector来存储，实际也可以用一个unordered_map<string,vector<string>>来存储，会更快一点。

```C++ []
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<string> vec;
		vector<vector<string>> res;
		for (string str : strs) {
			string tmp(str);
			sort(tmp.begin(), tmp.end());
			int i;
			for (i = 0; i < vec.size(); i++) {
				if (vec[i] == tmp) {
					res[i].push_back(str);
					break;
				}
			}
			if (i == vec.size()) {
				vec.push_back(tmp);
				res.push_back(vector<string>(1,str));
			}
		}
		return res;
	}
};
```

下面是用unordered_map的写法，执行用时超过86.17%
```C++ []
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> res;
		unordered_map<string, vector<string>> m;
		for (string str : strs) {
			string tmp(str);
			sort(tmp.begin(), tmp.end());
			m[tmp].push_back(str);
		}
		for (auto it : m) {
			res.push_back(it.second);
		}
		return res;
	}
};
```

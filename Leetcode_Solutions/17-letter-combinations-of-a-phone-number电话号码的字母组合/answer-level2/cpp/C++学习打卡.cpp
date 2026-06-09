### 解题思路
用队列依次处理每个数字

### 代码

```cpp
class Solution {
private:
	vector<vector<char>>trans = {
		{'a','b','c'},
		{'d','e','f'},
		{'g','h','i'},
		{'j','k','l'},
		{'m','n','o'},
		{'p','q','r','s'},
		{'t','u','v'},
		{'w','x','y','z'}
	};

public:
	vector<string> letterCombinations(string digits) {
		if (digits.length() == 0) { return{}; }
		string str;
		deque<string>tempStr;
		tempStr.push_back(str);
		for (char c : digits) {
			int c_to_i = c - '2';
			int queueSize = tempStr.size();
			while (queueSize--) {
				string temp = tempStr.front();
				tempStr.pop_front();
				for (int k = 0; k < trans[c_to_i].size(); k++) {
					tempStr.push_back(temp + trans[c_to_i][k]);
				}
			}
		}
		vector<string>ans(tempStr.size());
		for (int i = 0; i < ans.size(); i++) {
			ans[i] = tempStr.front();
			tempStr.pop_front();
		}
		return ans;
	}
};
```
### 解题思路
主要思路就是把A,B,C放到一个map里，key是字母，value是字母的个数。
1. 对map按value排序
2. 选剩余个数最多的字母，尝试插入结果字符串charInsert，如果不能插入，则换剩余次数次多的，依次类推，插入后，更新map
3. 反复执行1,2步骤，直到无法插入新的字符
难点主要在charInsert，如何判断是否能插入新的字符，我用了一个非常笨的办法。。。

### 代码

```cpp
class Solution {
public:
	vector<char> sortChar(map<char, int> charNum)
	{
		vector<char> ret;
		for (auto c : charNum) {
			if (c.second != 0) {
				ret.push_back(c.first);
			}
		}
		int len = ret.size();
		if (len == 1) {
			return ret;
		}
		for (int i = 0; i < len - 1; i++) {
			for (int j = i + 1; j < len; j++) {
				if (charNum[ret[i]] < charNum[ret[j]]) {
					char tmp = ret[j];
					ret[j] = ret[i];
					ret[i] = tmp;
				}
			}
		}
		return ret;
	}
	bool charInsert(string& ret, char test) {
		bool inserted = false;
		int n = ret.size();
		if (n <= 1) {
			ret.push_back(test);
			return true;
		}
		if (n == 2) {
			if (ret[0] == ret[1] && ret[0] == test) {
				return false;
			}
			ret.push_back(test);
			return true;
		}
		if (ret[0] != test) {
			ret.insert(0, 1, test);
			return true;
		}
		if (ret[0] == test && ret[1] != test) {
			ret.insert(0, 1, test);
			return true;
		}
		if (ret[n - 1] != test) {
			ret.push_back(test);
			return true;
		}
		if (ret[n - 1] == test && ret[n - 2] != test) {
			ret.push_back(test);
			return true;
		}
		for (int i = 1; i < n - 2; i++) {
			if ((ret[i] == test && ret[i + 1] == test) ||
				(ret[i - 1] == test && ret[i] == test) ||
				(ret[i + 1] == test && ret[i + 2] == test)) {
				continue;
			} else {
				ret.insert(i, 1, test);
				inserted = true;
				break;
			}
		}
		return inserted;
	}
	string longestDiverseString(int a, int b, int c) {
		map<char, int> charNum;
		string ret;
		charNum['a'] = a;
		charNum['b'] = b;
		charNum['c'] = c;
		bool inserted = true;
		while (inserted) {
			vector<char> test = sortChar(charNum);
			if (test.empty()) {
				return ret;
			}
			for (auto t : test) {
				inserted = charInsert(ret, t);
				if (inserted) {
					charNum[t]--;
					test = sortChar(charNum);
					break;
				}
			}
		}
		return ret;
	}
};
```
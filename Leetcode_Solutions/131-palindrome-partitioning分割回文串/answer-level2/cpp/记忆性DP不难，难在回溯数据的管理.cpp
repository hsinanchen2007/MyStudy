### 解题思路
1. 记忆hash做，动态规划，防止抑郁。
2. 返回数据每次都要拆包

### 代码

```cpp
class Solution {
public:
	vector<vector<string>> partition(string s) {
		return dp(s);
	}
	vector<vector<string>> dp(string s) {
		if (s.size() == 1)	// 判断单一字符
			return{ {s} };
		if (memory.count(s))  // 看是否求解过，求结果就记录下来。
			return memory[s];
		vector<vector<string>> paOfCurS; // 返回值拆包
		for (int i = s.length() - 1; i >= 0; i--) {  // 循环检查当前子问题。
			string rStr = s.substr(i);
			if (isPalidrom(rStr)) {
				string lStr = s.substr(0, i);
				if (lStr.empty()) {
					paOfCurS.push_back({ rStr });
					continue;
				}
				vector<vector<string>> lPara = dp(lStr);
				for (auto iter = lPara.begin(); iter != lPara.end(); iter++) {
					iter->push_back(rStr);
				}
				for (auto v : lPara)
					paOfCurS.push_back(v);
			}
		}
		memory.insert({ s,paOfCurS });   // 把该子问题记录下来。
		return paOfCurS; // 返回
	}
	bool isPalidrom(string s) {  // 判断回文。
		int len = s.length();
		for (int i = 0; i < len / 2 + 1; i++) {
			if (s[i] != s[len - i - 1])return false;
		}
		return true;
	}
private:
	map<string, vector<vector<string>>> memory;
};
```
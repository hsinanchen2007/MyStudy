执行用时 :8 ms, 在所有 C++ 提交中击败了78.95% 的用户
内存消耗 :9.7 MB, 在所有 C++ 提交中击败了13.30%的用户
```cpp
class Solution {
public:
	string mostCommonWord(string paragraph, vector<string>& banned) {
		unordered_set<string> bannedSet(banned.begin(), banned.end());
		unordered_map<string, int> cnt; cnt.reserve(paragraph.size());
		string word;
		for (size_t i = 0; i < paragraph.size(); i++) {
			auto& c = paragraph[i];
			if (isalpha(c)) {
				word.push_back(tolower(c));
				if (i == paragraph.size() - 1 || !isalpha(paragraph[i + 1])) {
					if (!bannedSet.count(word)) {
						cnt[word]++;
					}
					word.clear();
				}
			}
		}
		return max_element(cnt.begin(), cnt.end(), [](auto& a, auto& b) {
			return a.second < b.second;
			})->first;
	}
};
```
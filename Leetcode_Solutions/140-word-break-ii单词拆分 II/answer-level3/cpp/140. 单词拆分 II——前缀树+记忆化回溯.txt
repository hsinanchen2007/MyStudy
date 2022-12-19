通过前缀树，加快单词搜索的速度
通过记忆化，减少重复路径的搜索

```
class Solution {
	struct Node {
		int idx;
		struct Node* a[26];
		Node() {
			for (int i = 0; i < 26; i++) {
				a[i] = nullptr;
			}
			idx = -1;
		}
	};
private:
	void WordTree(Node* root, vector<string>& wordDict) {
		for (int i = 0; i < wordDict.size(); i++) {
			Node* tmp = root;
			for (int j = 0; j < wordDict[i].size(); j++) {
				int idx = wordDict[i][j] - 'a';
				if (!tmp->a[idx]) {
					tmp->a[idx] = new Node();
				}
				tmp = tmp->a[idx];
			}
			tmp->idx = i;
		}
	}
	vector<string> Dfs(Node* root, vector<string>& wordDict, string& s, int begin, unordered_map<int, vector<string>>& hashMap) {
		if (hashMap.find(begin) != hashMap.end()) {
			return hashMap[begin];
		}
		Node* tmp = root;
		vector<string> res;
		if (begin >= s.size()) {
			res.emplace_back("");
		}
		for (int i = begin; i < s.size(); i++) {
			int idx = s[i] - 'a';
			if (tmp->a[idx] != nullptr) {
				tmp = tmp->a[idx];
				if (tmp->idx != -1) {
					for (auto& str : Dfs(root, wordDict, s, i + 1, hashMap)) {
						res.emplace_back(wordDict[tmp->idx] + (!str.size() ? "" : " ") + str);
					}
				}
			} else {
				break;
			}
		}
		hashMap[begin] = res;
		return res;
	}
public:
	vector<string> wordBreak(string s, vector<string>& wordDict) {
		Node* root = new Node();
		WordTree(root, wordDict);
		unordered_map<int, vector<string>> hashMap;
		return Dfs(root, wordDict, s, 0, hashMap);
	}
};
```

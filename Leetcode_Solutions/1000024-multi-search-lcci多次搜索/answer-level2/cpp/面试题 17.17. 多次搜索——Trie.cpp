通过前缀树，可快速判断
```
class Solution
{
private:
	struct Node
	{
		Node* a[26];
		int idx;
		Node()
		{
			idx = -1;
			for (int i = 0; i < 26; i++) {
				a[i] = nullptr;
			}
		}
	};
	void Insert(Node* root, string s, int idx)
	{
		for (size_t i = 0; i < s.size(); i++) {
			int j = s[i] - 'a';
			if (root->a[j] == nullptr) {
				root->a[j] = new Node();
			}
			root = root->a[j];
		}
		root->idx = idx;
	}
	void Search(vector<vector<int>>& res, string& s, int idx, Node* root)
	{
		for (size_t i = 0; i < s.size(); i++) {
			int j = s[i] - 'a';
			if (root->a[j] == nullptr) {
				break;
			}
			root = root->a[j];
			if (root->idx != -1) {
				res[root->idx].push_back(idx);
			}
		}
	}
public:
	vector<vector<int>> multiSearch(string big, vector<string>& smalls)
	{
		Node* root = new Node();
		for (size_t i = 0; i < smalls.size(); i++) {
			Insert(root, smalls[i], i);
		}
		vector<vector<int>> res(smalls.size(), vector<int>{});
		for (size_t i = 0; i < big.size(); i++) {
			string s = big.substr(i, big.size() - i);
			Search(res, s, i, root);
		}
		return res;
	}
};
```

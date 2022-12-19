```
class Solution {
private:
	struct TreeNode
	{
		TreeNode* map[27];
		TreeNode* next;
		bool empty;
		bool printed;
		TreeNode()
		{
			memset(map, 0, sizeof(TreeNode*) * 26);
			next = 0;
			empty = true;
			printed = false;
		}
	};
	void buildTree(string word, TreeNode* head)
	{
		if (word.empty())
			return;
		string::reverse_iterator rit = word.rbegin();
		while (rit != word.rend())
		{
			if (head->map[*rit - 'a'])
			{
				head = head->map[*rit - 'a'];
				rit++;
			}
			else
			{
				head->map[*rit - 'a'] = new TreeNode();
				head->empty = false;
			}
		}
	}
	bool validNode(string word, int& len, TreeNode* head)
	{
		if (word.empty())
			return false;
		bool ret = false;
		string::reverse_iterator rit = word.rbegin();
		len = 0;
		while (rit != word.rend())
		{
			if (head->map[*rit - 'a'])
			{
				head = head->map[*rit - 'a'];
				rit++;
				len++;
			}
		}
		ret = head->empty & !head->printed;
		if (ret)
			head->printed = true;
		return ret;
	}
	TreeNode* head;
public:
	int minimumLengthEncoding(vector<string>& words) {

		if (words.empty())
			return 0;
		int ret = 0;
		head = new TreeNode();
		for (auto w : words)
			buildTree(w, head);
		for (auto w : words)
		{
			int len = 0;
			if (validNode(w, len, head))
				ret += len + 1;
		}
		return ret;
	}
};
```

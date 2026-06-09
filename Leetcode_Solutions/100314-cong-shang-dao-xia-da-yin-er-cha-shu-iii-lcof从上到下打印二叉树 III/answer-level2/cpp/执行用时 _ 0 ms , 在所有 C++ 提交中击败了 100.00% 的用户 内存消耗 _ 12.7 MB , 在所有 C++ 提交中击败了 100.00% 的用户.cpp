### 解题思路
用队列模仿二叉树的层次，用一个count来计数，确定是奇数层还是偶数层，
奇数层从左到右，偶数层从右到左（借助list的双端操作特性）。

### 代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	vector<vector<int> > levelOrder(TreeNode* pRoot) {
		if (pRoot == NULL) {
			return vector<vector<int>>();
		}
		queue<TreeNode*> sq;
		sq.push(pRoot);
		int count = 1;
		while (!sq.empty()) {
			vector<int> temp;
			list<int> ls;
			int len = sq.size();
			for (int i = 0; i < len; ++i) {
				TreeNode* node = sq.front();
				if (count % 2 == 0)
				{
					ls.push_front(node->val);
				}
				else {
					temp.push_back(node->val);
				}
				sq.pop();
				if (node->left) {
					sq.push(node->left);
				}
				if (node->right) {
					sq.push(node->right);
				}
			}
			if (count % 2 == 0) {
				for (list<int>::iterator it = ls.begin(); it != ls.end(); ++it) {
					temp.push_back(*it);
				}
				res.push_back(temp);
			}
			else {
				res.push_back(temp);
			}
			++count;
		}
		return res;
	}
private:
	vector<vector<int>> res;
};
```
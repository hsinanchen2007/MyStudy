### 深度优先搜索
1. 构造函数使用深度优先搜索的方式进行模拟，同时将所有node的val值压入set集合；
2. find查找时直接查找set集合即可。
```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class FindElements {
public:
	FindElements(TreeNode* root) {
		root->val = 0;
		dfsInit(root);
	}

	bool find(int target) {
		unordered_set<int>::iterator itFind = m_setNode.find(target);
		return itFind != m_setNode.end();
	}

private:
	void dfsInit(TreeNode* root) {
		m_setNode.insert(root->val);
		if (root->left != NULL) {
			root->left->val = 2 * root->val + 1;
			dfsInit(root->left);
		}
		if (root->right != NULL) {
			root->right->val = 2 * root->val + 2;
			dfsInit(root->right);
		}
	}

private:
	unordered_set<int> m_setNode;
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
```

### 解题思路
非递归解法：

先左后右最后中，  解决办法，也是记录中间，但是到中间的时候不是直接输出，而是看是不是访问过右边，访问过右边的话直接输出，没有访问过的话先去右边
所以唯一的区别就是用了一个set来记录某个是否已经访问右边，这样加一个栈就可以简单地实现了。
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
	 vector<int> postorderTraversal(TreeNode* root) {
		 vector<int> res;
		 stack<TreeNode*> nodeStack;
		 set<TreeNode*> record;
		 while (root != nullptr || !nodeStack.empty()) {
			 if (root != nullptr) {
				 nodeStack.push(root);
				 root = root->left;
			 }
			 if (root == nullptr) {
				 TreeNode* temp = nodeStack.top();
				 if (record.find(temp) != record.end()) {
					 nodeStack.pop();
					 res.push_back(temp->val);
				 }
				 else {
					 record.insert(temp);
					 root = temp->right;
				 }
			 }
		 }
		 return res;
	 }
 };
```

递归解法：送分题如下：
```
class Solution {
public:
	void postorder(TreeNode* root,vector<int>& result) {
		if (root == nullptr)
			return;
		postorder(root->left,result);
		postorder(root->right, result);
        result.push_back(root->val);
	}
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> result;
		postorder(root, result);
		return result;
	}
};

```

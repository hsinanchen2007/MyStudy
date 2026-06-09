递归解法如下：
```
class Solution {
public:
	void preorder(TreeNode* root,vector<int>& result) {
		if (root == nullptr)
			return;
		result.push_back(root->val);
		preorder(root->left,result);
		preorder(root->right, result);
	}
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> result;
		preorder(root, result);
		return result;
	}
};
```

下面是非递归的解法：
```
 class Solution {
 public:
	 vector<int> preorderTraversal(TreeNode* root) {
		 vector<int> result;
		 stack<TreeNode*> temp;
		 while (root!=nullptr || !temp.empty()) {
			 if (root == nullptr) {
				 root = temp.top();
				 temp.pop();
			 }
			 result.push_back(root->val);
			 if (root->right != nullptr) {
				 temp.push(root->right);
			 }
			 root = root->left;
		 }
		 return result;
	 }
 };
```


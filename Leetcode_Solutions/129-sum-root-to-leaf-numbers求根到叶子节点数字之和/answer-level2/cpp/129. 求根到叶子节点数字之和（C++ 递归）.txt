# 129. 求根到叶子节点数字之和
**思路**
采用递归的方式，每进入一层 `当前数*10+节点值`
到达叶子结点时，加入sum中。
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
class Solution {
private:
	int sum = 0;
public:
	void sumNumbersCicle( TreeNode* &root , int temp ){
		if( root->left == NULL && root->right == NULL ){
			sum += (temp*10+root->val);
			return;
		}
		if(root->left)
			sumNumbersCicle(root->left,temp*10+root->val);
		if(root->right)
			sumNumbersCicle(root->right,temp*10+root->val);
	}
    int sumNumbers(TreeNode* root) {
		if(root)
			sumNumbersCicle(root,0);
		return sum;
    }
};
```


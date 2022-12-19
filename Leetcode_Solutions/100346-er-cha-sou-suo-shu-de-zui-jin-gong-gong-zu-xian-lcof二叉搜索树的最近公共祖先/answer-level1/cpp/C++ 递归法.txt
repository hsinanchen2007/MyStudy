### 解题思路
采用后序遍历对树进行遍历；
对于BST树，由于其具有左子树小于根节点，右子树大于根节点，因此如果当前节点小于p和q，则向右子树找，如果当前节点大于p，q，则向左子树找

### 代码

```cpp
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if(root==NULL||p==NULL||q==NULL) return NULL;//rooot,p,q一者为空
        //如果当前节点小于p和q，则向右子树找
		if (root->val < q->val && root->val < p->val) return lowestCommonAncestor(root->right, p, q);
        //当前节点大于p，q，则向左子树找
		if (root->val > q->val&& root->val > p->val) return lowestCommonAncestor(root->left, p, q);
		//如果位于之前，则返回根节点
		return root;
	}
};
```
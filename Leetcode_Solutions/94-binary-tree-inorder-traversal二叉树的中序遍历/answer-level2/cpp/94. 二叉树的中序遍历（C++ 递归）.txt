# 94. 二叉树的中序遍历
**思路**
- 二叉树的每一个节点由（根节点，左右子节点指针）构成。所以可以把二叉树的中序遍历归结到每个节点中。
- 中序遍历对于每个二叉树节点来说：
    1. 就是先遍历每个节点的左子树；
    2. 再该节点左子树全部遍历完成后，访问该节点的数值；
    3. 最后访问其右子树。

- 对于叶子结点我们可以看为左右节点都为空的节点，但本质上与其他的节点无区别，如图中值为1的节点。

![图片.png](https://pic.leetcode-cn.com/059ac33b0ee36c222e7205da23666c846bd356a9d0492d95faa3038e08b44a7a-%E5%9B%BE%E7%89%87.png)

- 综上所述，中序遍历就可以归结到每个节点中，从而可以采用递归的方式，遍历每个节点。当遇到空节点时返回。

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
	vector<int> rst;
public:
	void inorderTraversalCicle(TreeNode* root){
		if(!root)
			return;
		inorderTraversalCicle(root->left);
		rst.push_back(root->val);
		inorderTraversalCicle(root->right);
	}
	
    vector<int> inorderTraversal(TreeNode* root) {
        if(root)
		inorderTraversalCicle(root);
	return rst;
    }
};
```

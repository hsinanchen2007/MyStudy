### 解题思路
前序只用来取根节点。中序被根节点分拆左右子树。
i表示根在中序中的索引，理论上用二分查找更快。
![image.png](https://pic.leetcode-cn.com/cabe9f3f6560ea2c775e9956329c3b4cc373e0babf67d37ae9ef6f7aa8d91b45-image.png)

### 代码

```c
struct TreeNode *buildTree(int *preorder, int preorderSize, int *inorder, int inorderSize)
{
	if (!preorderSize)
		return 0;
	struct TreeNode *root = malloc(sizeof(struct TreeNode));

	root->val = preorder[0];
	int i = 0;
	for (; i < preorderSize; i++)
		if (root->val == inorder[i])
			break;

	root->left = buildTree(preorder + 1, i, inorder, 0);
	root->right =
		buildTree(preorder + i + 1, preorderSize - i - 1, inorder + i + 1, 0);

	return root;
}
```
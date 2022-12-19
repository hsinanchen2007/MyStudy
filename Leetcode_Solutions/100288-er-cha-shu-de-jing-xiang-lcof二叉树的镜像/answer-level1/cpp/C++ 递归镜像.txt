### 解题思路
先序遍历
首先判断左右节点是否都不为null，如果不为，则进行交换；
然后对其左子树镜像，再对其右子树镜像

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
    	TreeNode* mirrorTree(TreeNode* root) {
		if (root == NULL) return NULL;//为空不进行交换
		else if(root->left!=NULL||root->right!=NULL)//左节点和右节点都不为null时就进行交换
		{
			TreeNode* temp = root->left;
			root->left = root->right;
			root->right = temp;
            if(root->left!=NULL) mirrorTree(root->left);//左子树存在则进行镜像
			if(root->right!=NULL) mirrorTree(root->right);//右子树存在则进行镜像
		}
		return root;
	}
};
```
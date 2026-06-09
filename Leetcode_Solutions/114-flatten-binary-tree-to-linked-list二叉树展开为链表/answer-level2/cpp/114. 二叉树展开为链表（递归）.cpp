# 114. 二叉树展开为链表
**思路：**
采用后序遍历递归为模板进行修改：
- 首先通过后序遍历递归找到第一个叶子节点上面的节点；
```
flattenRecursion(root->left);
flattenRecursion(root->right);
```

- 如果该节点有左子树的话记录右子树位置：`if(root->left)`
    1. 记录当前节点右子树的位置；`TreeNode* temp = root->right;`
    2. 将该节点右子树指向其节点左子树；`root->right = root->left;`
    3. 将左子树置空      `root->left = NULL;`
    4. 再通过循环找到此时右子树的尾部，将记录的之前的右子树添加上去。
        ```
        while(root->right){
            root = root->right;
        }
        root->right = temp;
        ```
    5. 递归完成
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
public:
	void flattenRecursion(TreeNode* root){
		if( !root )
			return;
		flattenRecursion(root->left);
		flattenRecursion(root->right);
		
		if(root->left){
			TreeNode* temp = root->right;
			root->right = root->left;
			root->left = NULL;
			while(root->right){
				root = root->right;
			}
			root->right = temp;
		}
	}
    void flatten(TreeNode* root) {
        if(root)
        	flattenRecursion(root);
    }
};
```

### 解题思路
此处撰写解题思路
算法思想：递归调用，只需要存储左子树的左叶子之和，右子树的左子叶之和。

### 代码

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int sumOfLeftLeaves(struct TreeNode* root){
    if(root==NULL) return 0;

//   left存root的左子树的左叶子之和，right存右子树的左叶子之和
//  若root->left为左叶子，current存root->left的值
    int left=0,right=0,current=0;
    if(root->left != NULL && root->left->left==NULL && root->left->right == NULL)
        current = root->left->val;
    else
        left = sumOfLeftLeaves(root->left);//左子树的值
        right = sumOfLeftLeaves(root->right);//右子树的值
        return right+left+current;
}
```
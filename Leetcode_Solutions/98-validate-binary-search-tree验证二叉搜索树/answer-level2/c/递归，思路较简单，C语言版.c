### 解题思路
对于每一颗子树，把根结点的值记为**target**。
我们可以设计一个函数以遍历该子树的左右子树的所有结点，若左子树的所有结点的值都小于target且右子树的所有结点的值
都大于target，则返回true，一旦途中有不符合条件的，返回false。
然后利用**递归**的思路判断该子树的左子树和右子树，具体实现看代码（附注释）

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

/* 深搜函数，target为根结点的值，Position为0说明在遍历左子树，为1说明在遍历右子树 */
bool DFS(struct TreeNode* root, int target, int Position){
    if (root == NULL)   /* 到底就返回true */
        return true;
    
    if (Position == 0 && root->val >= target)
        return false;
    if (Position == 1 && root->val <= target)
        return false;
    return DFS(root->left, target, Position) && DFS(root->right, target, Position);
    /* 注意这里的Position是不变的，root->left和root->right 相对于根（值为target的结点）都在一颗子树上 */
}

bool isValidBST(struct TreeNode* root){
    if (root == NULL)
        return true;
    
    return DFS(root->left, root->val, 0) && DFS(root->right, root->val, 1) && 
            isValidBST(root->left) && isValidBST(root->right);
}
```
### 解题思路
使用后序遍历方法，从后往前将每个节点的子树（如果有）左右互换。

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

//将一个节点的子树左右互换
void swapChildTreeNode(struct TreeNode* root) {
    struct TreeNode* temp;
    temp = root -> left;
    root -> left = root -> right;
    root -> right = temp;
}

//递归进行后序遍历并完成左右互换
struct TreeNode* mirrorTree(struct TreeNode* root){
    if(root == NULL) {
        return root;
    }
    if(root -> left != NULL) {
        mirrorTree(root -> left);
    }
    if(root -> right != NULL) {
        mirrorTree(root -> right);
    }
    swapChildTreeNode(root);
    return root;
}
```
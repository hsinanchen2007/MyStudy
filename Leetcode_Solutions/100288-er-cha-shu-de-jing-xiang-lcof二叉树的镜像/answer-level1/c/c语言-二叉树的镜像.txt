### 解题思路
执行用时 :0 ms, 在所有 C 提交中击败了100.00% 的用户
内存消耗 :7.1 MB, 在所有 C 提交中击败了100.00%的用户
本质是后序遍历递归，先遍历左右子树，再将自己的左右孩子节点交换

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
void preorder(struct TreeNode *root){
    if(root==NULL)return ;
    if(root->left)preorder(root->left);
    if(root->right)preorder(root->right);
    if(root->left&&root->right){
       struct TreeNode* temp=root->left;
        root->left=root->right;
        root->right=temp;
    }
    else if(root->left&&!root->right){
        root->right=root->left;
        root->left=NULL;
    }
    else if(!root->left&&root->right){
         root->left=root->right;
        root->right=NULL;
    }
}

struct TreeNode* mirrorTree(struct TreeNode* root){
    preorder(root);
    return root;
}
```
### 解题思路
当前节点的长度，可以等价为求左子树深度+右子树深度。
我们求的，也就是所有节点中的最大长度。

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
int max_lens = 0;
int maxTreeDepth(struct TreeNode* root)
{
    if(root == NULL) return 0;
    int left = 0,right = 0;
    if(root->left)  //左树深度
        left = 1 + maxTreeDepth(root->left);
    else
        left = 0;
    if(root->right)  //右树深度
        right = 1 + maxTreeDepth(root->right);
    else
        right = 0;
    int current_lens = left + right;  //当前节点长度
    if(max_lens < current_lens) max_lens = current_lens;  //最大长度是否更新
    return left > right ? left : right;
}

int diameterOfBinaryTree(struct TreeNode* root){
    max_lens = 0;
    maxTreeDepth(root);
    return max_lens;
}

```
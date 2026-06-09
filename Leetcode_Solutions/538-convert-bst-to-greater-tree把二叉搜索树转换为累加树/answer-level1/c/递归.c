### 解题思路
有两个地方要注意
根的值迭代时加上的值  落在右子树的最左边的孩子（最左边的孩子是没有处理之前右子树最小的结点，所以前面比根节点的值大的结点值的和为最左边的孩子的值）
同理，在递归左子树之前，要处理左子树最最右结点

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


struct TreeNode* convertBST(struct TreeNode* root){
    if(root==NULL) return NULL;
    if(!root->left&&!root->right) return root;
    if(root->right){
        struct TreeNode *p=convertBST(root->right);
        while(p->left) p=p->left;
        root->val+=p->val;
    }
    if(root->left){
        struct TreeNode *q=root->left;
        while(q->right) q=q->right;
        q->val+=root->val;
        convertBST(root->left);
    }
    return root;
}
```
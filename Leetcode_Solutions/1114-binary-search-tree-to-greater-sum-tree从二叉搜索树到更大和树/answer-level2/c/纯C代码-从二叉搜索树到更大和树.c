### 解题思路
此处撰写解题思路

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
void setNodeVal(struct TreeNode *root, int *sum){
    if (root == NULL){
        return;
    }
    //先设置root的右子节点的val
    if (root->right != NULL){
        setNodeVal(root->right, sum);
    }
    //设置root节点的val
    *sum += root->val;
    root->val = *sum;
    //后设置root的左子节点的val
    if (root->left != NULL){
        setNodeVal(root->left, sum);
    }
    
    return;
}

struct TreeNode* bstToGst(struct TreeNode* root){
    int sum = 0;
    //设置root节点的val
    setNodeVal(root, &sum);

    return root;
}
```
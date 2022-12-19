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


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 void InOrder(struct TreeNode*root,int *result,int *returnSize){
     if(root){
         InOrder(root->left,result,returnSize);
         result[(*returnSize)++] = root->val;
         InOrder(root->right,result,returnSize);
     }
 }

int Tree_node(struct TreeNode* root){
    if(root==NULL) return 0;
    return Tree_node(root->left)+Tree_node(root->right)+1;
}

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int node_number = Tree_node(root);
    int* result = (int *)malloc(node_number*sizeof(int));
    *returnSize = 0;
    InOrder(root,result,returnSize);
    return result;
}
```
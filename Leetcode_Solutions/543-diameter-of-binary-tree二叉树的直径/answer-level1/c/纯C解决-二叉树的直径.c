### 解题思路
这道题有点儿坑，刚开始以为是只需要求出根节点左右两边子树的深度相加即可，后来发现过不了，原因出在子树的两个节点也有可能是最长路径。

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

int searchDeep(struct TreeNode *root,int *length)//找到该树中能够到达的最深
{
    if(!root)
    return 0;
    if(!root->left&&!root->right)
    return 1;
    int leftl=searchDeep(root->left,length);
    int rightl=searchDeep(root->right,length);
    if(leftl+rightl>*length)
    *length=leftl+rightl;
    return (leftl>rightl?leftl:rightl)+1;
}
int diameterOfBinaryTree(struct TreeNode* root){
    if(!root)
    return 0;
    int length=0;
    int leftl=searchDeep(root->left,&length);
    int rightl=searchDeep(root->right,&length);
    return length>(leftl+rightl)?length:(leftl+rightl);
}
```
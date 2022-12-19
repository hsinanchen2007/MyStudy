### 解题思路
![Screenshot from 2019-12-04 21-13-22.png](https://pic.leetcode-cn.com/26475f1b1a5cf94c6d2b12bdb5b612e74dd5761174bd4d3f904c6cbe1cee6e35-Screenshot%20from%202019-12-04%2021-13-22.png)
 
运用递归思想，根据图片理解每一步

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

 int treeSize(struct TreeNode* root)
 {
     if (root == NULL)
     {
         return 0;
     } 
     return treeSize(root->left) + treeSize(root->right) +1;
 }

void zhongxu(struct TreeNode* root,int * p,int * index)
{
    if(root == NULL)
        return;
    zhongxu(root->left,p,index);
    p[(*index)++] = root->val;
    zhongxu(root->right,p,index);
    
}

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int treesize = treeSize(root);
    * returnSize = 0;
    if (treesize == 0)
    {
        return NULL;
    }
    int * pArray = (int *)malloc(sizeof(int) * treesize);
    zhongxu(root,pArray,returnSize);
    return pArray;



}
```
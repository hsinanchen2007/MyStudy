### 解题思路
最简单的递归思路，然鹅时空间都不太理想，求大佬指点如何改进。

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


struct TreeNode* searchBST(struct TreeNode* root, int val){
    if(root==NULL) return NULL;
    if(root->val==val){
        return root;
    }else if(root->val<val){//值小时递归右子树
        return searchBST(root->right,val);
    }else{
        return searchBST(root->left,val);
    }
}
```
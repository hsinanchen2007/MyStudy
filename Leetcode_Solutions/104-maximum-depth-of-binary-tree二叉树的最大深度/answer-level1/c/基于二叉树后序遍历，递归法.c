### 解题思路
![图片.png](https://pic.leetcode-cn.com/26919ac756550f4dd6828caeee96923bbbe12b0eb0882aa4f7cfed5742ac811e-%E5%9B%BE%E7%89%87.png)


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


#define MAX (left>right?left:right)+1
int maxDepth(struct TreeNode* root){
    if(root==NULL){
        return 0;
    }
    int left=maxDepth(root->left);
    int right=maxDepth(root->right);
    return MAX;
}
```
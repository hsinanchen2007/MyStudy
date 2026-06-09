### 解题思路
![image.png](https://pic.leetcode-cn.com/971794421a7eebbf36ceb6373f68e03a66d1895ca4c59f4d2d68ae7d9528f9a5-image.png)


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


bool hasPathSum(struct TreeNode* root, int sum){
     //怎么个计算法,注意是看根节点到叶节点的和
    if(!root){
        return false;
    }
    else if(root->val == sum && !root->left && !root->right){
        return true;
    }
    else
        return hasPathSum(root->left,sum - root->val) || hasPathSum(root->right,sum - root->val);
}
```
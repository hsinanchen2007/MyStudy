### 解题思路
递归遍历每一个节点的深度，然后比较取较小者。需要注意的是当left或right为空时，直接取另一个。

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


int minDepth(struct TreeNode* root){
      if(root == NULL)  return 0;
      int left = minDepth(root->left)+1;
      int right = minDepth(root->right)+1;

      if(left == 1) return right;
      if(right == 1) return left;

      return left<right?left:right;
}
```
### 解题思路
![捕获.PNG](https://pic.leetcode-cn.com/9b4d86733353f5181d94c6570804b30b0a7f6f687af3892e937ddddf89826245-%E6%8D%95%E8%8E%B7.PNG)
我也不敢相信
### 代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
      if(!root||!root->left&&!root->right) return root;
      TreeNode *currleft=root->left;
      TreeNode *currright=root->right;
      //root->left=NULL;
      //root->right=NULL;
      root->left=invertTree(currright);
      root->right=invertTree(currleft);
      return root;
    }
};
```
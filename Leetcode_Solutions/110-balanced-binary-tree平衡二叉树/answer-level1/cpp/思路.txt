### 解题思路
自底向上复杂度低一些
但是需要考虑到 result结果的传递，可以使用全局变量

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
    bool res = true;
    int heightTree(TreeNode* root){
      if(!root) return 0;
      int left = heightTree(root->left) + 1;
      int right = heightTree(root->right) + 1;

      if(abs(left - right) > 1)
        res = false;

      return max(left, right);
    }

    bool isBalanced(TreeNode* root) {
      if(!root) return true;

      heightTree(root);
      return res;
    }
};
```
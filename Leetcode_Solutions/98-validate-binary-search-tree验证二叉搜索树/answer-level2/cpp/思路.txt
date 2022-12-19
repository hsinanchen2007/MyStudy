### 解题思路
涉及到一个上下界问题，写dfs的时候需要注意参数传入的问题
或者中序遍历，是一个比较简单的方法

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
    bool dfs(TreeNode* root, int* low, int* high){
      if(low && root->val <= *low) return false;
      if(high && root->val >= *high) return false;

      if(root->left && !dfs(root->left, low, &root->val))
        return false;
      if(root->right && !dfs(root->right, &root->val, high))
        return false;

      return true;
    }

    bool isValidBST(TreeNode* root) {
      if(!root) return true;

      return dfs(root, NULL, NULL);
    }
};
```
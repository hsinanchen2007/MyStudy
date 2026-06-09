### 解题思路
很像94题中序排序的线索二叉树方法，还是需要理清指针往哪边去指
画图多看看

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
    void flatten(TreeNode* root) {
      if(!root) return;

      TreeNode* cur = root;
      TreeNode* pre = NULL;

      while(cur){
        if(cur->left == NULL){
          cur = cur->right;
        }else{
          pre = cur->left;
          while(pre->right){
            pre = pre->right;
          }
          pre->right = cur->right;
          cur->right = cur->left;
          cur->left = NULL;
          cur = cur->right;
        }
      }
    }
};
```
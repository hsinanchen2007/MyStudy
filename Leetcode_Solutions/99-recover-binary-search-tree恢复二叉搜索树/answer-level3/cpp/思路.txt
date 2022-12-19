### 解题思路
线索树，需要很熟练掌握中序遍历，如果空间要求是1，那一段是莫斯比遍历
另外莫斯比遍历还有一种会把树的结构破坏

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
    void recoverTree(TreeNode* root) {
      TreeNode *first = NULL, *second = NULL;
      TreeNode* cur = root;
      TreeNode* pre = NULL;

      while(cur){
        if(cur->left == NULL){
          if(pre != NULL && cur->val < pre->val){
            if(first == NULL)
              first = pre;
            second = cur;
          }
          pre = cur;
          cur = cur->right;
        }else{
          TreeNode* tmp = cur->left;
          while(tmp->right != NULL && tmp->right != cur){
            tmp = tmp->right;
          }

          if(tmp->right == NULL){
            tmp->right = cur;
            cur = cur->left;
          }else if(tmp->right == cur){
            if(pre != NULL && cur->val < pre->val){
              if(first == NULL)
                first = pre;
              second = cur;
            }
            tmp->right = NULL;
            pre = cur;
            cur = cur->right;
          }
        }
      }
      swap(first->val, second->val);
      return;
    }
};
```
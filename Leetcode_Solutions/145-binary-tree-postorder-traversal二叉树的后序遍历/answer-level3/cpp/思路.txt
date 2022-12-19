### 解题思路
整体和中序很像

需要加一个pre节点，纪录上一次的访问节点是什么

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
    vector<int> postorderTraversal(TreeNode* root) {
      vector<int> res;
      if(!root) return res;

      stack<TreeNode*> s;
      TreeNode* cur = root;
      TreeNode* pre = NULL;

      while(!s.empty() || cur){
        while(cur){
          s.push(cur);
          cur = cur->left;
        }

        cur = s.top();

        if(cur->right == NULL || cur->right == pre){
          s.pop();
          res.push_back(cur->val);
          pre = cur;
          cur = NULL;
        }else{
          cur = cur->right;
        }
      }

      return res;
    }
};
```
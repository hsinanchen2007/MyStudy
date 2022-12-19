借助一个栈，先变量完当前节点之后，把它的右子节点压入栈中。然后更新当前节点为它的左子节点，如果更新后节点为空，那么从栈里面pop一个出来赋值给当前节点。进入下一个循环。
```
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
    vector<int> preorderTraversal(TreeNode* root) {
      if (root == NULL) return {};
      vector<int> res;
      stack<TreeNode*> st;
      TreeNode* p = root;
     
      while(p != NULL) {
        res.emplace_back(p->val);
        if (p->right != NULL) {
          st.emplace(p->right);
        }
        p = p->left;
        if (p == NULL && !st.empty()) {
          p = st.top();
          st.pop();
        }
      }
      
      
      return res;  
    }
};
```
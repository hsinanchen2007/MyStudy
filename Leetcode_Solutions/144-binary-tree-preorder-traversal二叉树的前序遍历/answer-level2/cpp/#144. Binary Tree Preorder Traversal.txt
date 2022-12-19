# Recursive Approach

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
    vector<int> preorderTraversal(TreeNode* root) {
      if (root == NULL) {
        return ans;
      } else {
        ans.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
      }
      return ans;
    }
private:
    vector<int> ans;
};
```

# Iterative Approach
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
    vector<int> preorderTraversal(TreeNode* root) {
      vector<int> ans;
      
      // if null
      if (root == NULL) {
        return {};
      } 
      
      // construct stack, push root
      stack<TreeNode*> NodeStack;
      NodeStack.push(root);
      
      // iterative
      while (!NodeStack.empty()) {
        TreeNode* node = NodeStack.top();
        ans.push_back(node->val);
        NodeStack.pop();
        
        if (node->right != NULL) {
          NodeStack.push(node->right);          
        }
        if (node->left != NULL) {
          NodeStack.push(node->left);
        }
      }
      
      return ans;
    }
};
```
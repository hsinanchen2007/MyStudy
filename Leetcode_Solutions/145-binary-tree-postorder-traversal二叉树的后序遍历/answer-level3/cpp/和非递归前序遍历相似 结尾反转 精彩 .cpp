class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
           vector<int> res;
    stack<TreeNode*> stack;
 
     stack.push(root);
     while(!stack.empty())
    {
     TreeNode* node = stack.top();
     stack.pop();
     if(node==NULL) continue;
     res.push_back(node->val);

         stack.push(node->left);
         stack.push(node->right);
     }
    reverse(res.begin(),res.end());
      return res;
    }
};
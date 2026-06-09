```
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == NULL) return result;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            TreeNode* node = s.top();
            s.pop();
            while(node){
                result.push_back(node->val);
                if(node->right)
                    s.push(node->right);
                node = node->left;
            }
        }
        return result;
    }
};
```

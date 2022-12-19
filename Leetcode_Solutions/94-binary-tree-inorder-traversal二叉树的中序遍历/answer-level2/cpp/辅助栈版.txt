
利用辅助栈求解
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {

        stack <TreeNode*> S;
        vector <int> V;
        while(true)
        {
            AlongLeftBran(S,root);
            if(S.empty()) break;
            root = S.top();
            V.push_back(root->val);
            S.pop();
            root = root->right;
            
        }
        return V;
    }
    void AlongLeftBran(stack<TreeNode*> &S,TreeNode* x)
{
    while(x)
      {  S.push(x); x=x->left;}
}
    
};
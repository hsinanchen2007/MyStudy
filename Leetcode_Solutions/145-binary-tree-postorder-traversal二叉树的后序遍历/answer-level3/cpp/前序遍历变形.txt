因为前序遍历为root-root->left-root->right,而后续遍历为root->left-root->right-root;
因此修改前序的代码为root-root->right-root->left，恰好为后续的逆序。逆向输出序列即可。
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>v;
        stack<TreeNode*>s;
        while(root != NULL || !s.empty()){
            while(root != NULL){
                s.push(root);
                v.push_back(root->val);
                root = root->right;
            }
            root = s.top();
            s.pop();
            root = root->left;
        }
        int e;
        for(int i=0;i<v.size()/2;i++){
            e = v[i];
            v[i] = v[v.size()-1-i];
            v[v.size()-1-i] = e;
        }
        return v;
    }
};
```







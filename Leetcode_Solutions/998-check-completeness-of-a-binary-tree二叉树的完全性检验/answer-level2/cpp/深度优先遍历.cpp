```
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if(!root) return true;
        vector<unsigned int> v = {1};
        helper(root,1,v);
        return v.size() == *(max_element(v.begin(),v.end()));
        
    }
    
    void helper(TreeNode* node, unsigned int i, vector<unsigned int>& v){
        if(node->left){
            v.push_back(2*i);
            helper(node->left, 2*i, v);
        }
        if(node->right){
            v.push_back(2*i+1);
            helper(node->right, 2*i+1, v);
        }
    }
};
```

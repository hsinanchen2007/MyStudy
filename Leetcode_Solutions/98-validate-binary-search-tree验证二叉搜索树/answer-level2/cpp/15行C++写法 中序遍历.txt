```
class Solution {
public:
    long pre = LONG_MIN;
    int flag = true;
    
    bool isValidBST(TreeNode* root) {
        if(root == nullptr)
            return true;
        
        flag = isValidBST(root -> left);
        
        if(!flag || root -> val <= pre)
            return false;
        
        pre = root -> val;
        
        flag = isValidBST(root -> right);
        if(!flag)
            return false;
        
        return true;
    }
};
```

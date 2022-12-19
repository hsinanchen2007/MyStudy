```
class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        if(root == NULL) return true;
        return sub_judge(root,root->val);
    }
    bool sub_judge(TreeNode* root,int key){
        if(root == NULL) return true;
        if(root && root->val != key) return false;
        bool left = sub_judge(root->left,key);
        bool right = sub_judge(root->right,key);
        return left&&right;
    }
};
```

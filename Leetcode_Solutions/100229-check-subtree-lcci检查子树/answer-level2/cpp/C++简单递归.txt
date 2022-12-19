```
class Solution {
public:
    bool checkSubTree(TreeNode* t1, TreeNode* t2) {
        if(!t1 && !t2) return true;
        if(!t1 || !t2) return false;
        if(!t1->left && !t1->right && !t2->left && !t2->right && t1->val!=t2->val) return false;

        if(t1->val==t2->val)
            return checkSubTree(t1->left,t2->left) && checkSubTree(t1->right,t2->right);
        else
            return checkSubTree(t1->left,t2) || checkSubTree(t1->right,t2);
    }
};
```
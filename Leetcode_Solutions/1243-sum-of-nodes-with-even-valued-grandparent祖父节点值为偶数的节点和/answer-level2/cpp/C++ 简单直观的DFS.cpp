```
class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        return sumEvenGrandparent(root, -1, -1);
    }
    int sumEvenGrandparent(TreeNode* root, int parent, int grandparent ){
        if(root == nullptr) return 0;
        int res = 0;
        if(grandparent%2 == 0) res += root->val;
        res += sumEvenGrandparent(root->left, root->val, parent);
        res += sumEvenGrandparent(root->right, root->val, parent);
        return res;
    }
};
```

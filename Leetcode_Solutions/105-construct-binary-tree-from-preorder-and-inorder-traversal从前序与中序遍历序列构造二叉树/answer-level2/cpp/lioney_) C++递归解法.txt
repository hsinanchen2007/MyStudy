```
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
    TreeNode* helper(vector<int>& preorder, int pleft, int pright, vector<int>& inorder, int ileft, int iright) {
        if(pleft > pright || ileft > iright) return nullptr;
        int i = ileft;
        for(; i<=iright; i++) {
            if(inorder[i] == preorder[pleft])
                break;
        }
        TreeNode* t = new TreeNode(preorder[pleft]);
        t->left = helper(preorder, pleft+1, pleft+i-ileft, inorder, ileft, i-1);
        t->right = helper(preorder, pleft+i-ileft+1, pright, inorder, i+1, iright);
        return t;
    }
};
```

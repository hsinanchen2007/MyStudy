```class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(!root) return 0;//若树为空返回0
        if(root->val>R)//若根节点比R还大 那只到根节点的左子树中找
            return rangeSumBST(root->left,L,R);
        else if(root->val<L) //若根节点比 L还小 那知道根节点的右子树中找
            return rangeSumBST(root->right,L,R);
        else//若根节点在L与R之间 加上根节点的值 再到左右子树中找
            return root->val+rangeSumBST(root->left,L,R)+rangeSumBST(root->right,L,R);
    }
};
```

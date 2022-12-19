根据后续遍历，先遍历左子树，再遍历右子树，最后再遍历根节点，然后左子树与右子树继续这样遍历，直到为NULL
vector<int> postorderTraversal(TreeNode* root) {
        vector<int> nums;
        behindorder(root,&nums);
        return nums;
    }
    void behindorder(TreeNode* TT,vector<int> *nums)
    {
        if(TT)
        {
            behindorder(TT->left,nums);
            behindorder(TT->right,nums);
            (*nums).push_back(TT->val);
        }
    }
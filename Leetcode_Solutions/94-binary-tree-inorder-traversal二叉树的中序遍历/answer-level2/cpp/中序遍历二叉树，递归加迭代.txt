//递归
class Solution {
public:
    void myfun(TreeNode* root,vector<int>* x)
    {
        if (root)
        {
            myfun(root->left,x);
            x->push_back(root->val);
            myfun(root->right,x);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        myfun(root,&res);
        return res;
    }
};
//迭代
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> f;
        vector<int> res;
        TreeNode*T=root;
        while (T || !f.empty())
        {
            while (T)
            {
                f.push(T);
                T=T->left;
            }
            if (!f.empty())
            {
                res.push_back(f.top()->val);
                T=f.top()->right;
                f.pop();
            }
        }
        return res;
    }
};
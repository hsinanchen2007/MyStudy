```
class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        TreeNode* n = root;
        stack<TreeNode*> stk;
        int total = 0;
        while(n->val != L)
        {
            if(n->val > L)
            {
                stk.push(n);
                n = n->left;
            }
            else
            {
                n = n->right;
            }
        }
        while(n->val != R)
        {
            total += n->val;
            if(n->right != NULL)
            {
                n = n->right;
                while(n != NULL)
                {
                    stk.push(n);
                    n = n->left;
                }
            }
            n = stk.top();
            stk.pop();
        }
        total += n->val;
        return total;
    }
};
```

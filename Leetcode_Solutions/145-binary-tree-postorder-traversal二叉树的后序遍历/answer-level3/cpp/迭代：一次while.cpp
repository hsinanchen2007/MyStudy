一个辅助栈
1. 若root不为空，则压入栈
2. 令root指向其左子节点，重复步骤1
3. 若root为空，令root指向栈顶节点
4. 判断root右子节点是否为空或者是否等于pre
5. 若是，则root出栈，pre指向root,root置空
6. 若不是，则root指向其右子节点，pre置空
7. 重复上述步骤，知道栈为空，root为空
``` C++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root==NULL) return res;
        stack<TreeNode*> s;
        TreeNode* pre=NULL;
        while(s.size()||root)
        {
            if(root)
            {
                s.push(root);
                root=root->left;
            }
            else
            {
                root=s.top();
                if(root->right==NULL||root->right==pre)
                {
                    s.pop();
                    res.push_back(root->val);
                    pre=root;
                    root=NULL;
                    
                }
                else
                {
                    pre=NULL;
                    root=root->right;
                }
            }
        }
        return res;
    }
};
```
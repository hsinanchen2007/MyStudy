用栈存储层次遍历结果，再依次压入容器
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;

        if(root==NULL)
            return res;
        
        stack<vector<int>> sv;
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.size())
        {
            int len=q.size();
            vector<int> temp;
            for(int i=0;i<len;i++)
            {
                root=q.front();
                temp.push_back(root->val);
                q.pop();
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
            }
            sv.push(temp);

        }
        while(sv.size())
        {
            res.push_back(sv.top());
            sv.pop();
        }
        return res;
    }
};
```
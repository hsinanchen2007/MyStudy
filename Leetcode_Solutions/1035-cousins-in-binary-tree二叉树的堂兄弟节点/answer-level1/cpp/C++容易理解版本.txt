```
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
    bool isCousins(TreeNode* root, int x, int y) {
        map<int, int> Mdepth;
        map<int, TreeNode*> Mroot;
        queue<TreeNode*> Q;
        Q.push(root);
        int depth = 0;
        while(!Q.empty())
        {
            depth ++;
            int len = Q.size();
            for(int i = 0; i < len; i++)
            {
                TreeNode* node = Q.front();
                Q.pop();
                if(node->left)
                {
                    Q.push(node->left);
                    Mroot[node->left->val] = node;
                    Mdepth[node->left->val] = depth;
                }
                if(node->right)
                {
                    Q.push(node->right);
                    Mroot[node->right->val] = node;
                    Mdepth[node->right->val] = depth;
                }
            }
        }
        if(Mroot[x] != Mroot[y] && Mdepth[x] == Mdepth[y])
            return true;
        return false;
    }
};
  
    
```

层级遍历
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
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        queue<TreeNode *> que;
        que.push(root);
        int res = 0;
        while(!que.empty()) {
            int size = que.size();
            res ++;
            for(int i = 0; i < size; i++) {
                TreeNode * temp = que.front();
                que.pop();
                if(temp->left) 
                    que.push(temp->left);  
                if(temp->right)
                    que.push(temp->right);
                if(temp->left == NULL && temp->right == NULL)
                    return res;
            }
        }
        return res;
    }
};
使用一个队列
每次出队的时候将这个节点的左右孩子节点入队

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
    vector<int> levelOrder(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        if(root==nullptr)
        return ans;

        q.push(root);

        while(!q.empty())
        {
           
            TreeNode *tmp=q.front(); 
            ans.push_back(tmp->val);
            q.pop();
            if(tmp->left!=nullptr) q.push(tmp->left);
            if(tmp->right!=nullptr) q.push(tmp->right);
        }
        return ans;

    }
};
```

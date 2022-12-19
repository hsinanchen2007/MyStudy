1. 层次遍历二叉树
2. 求每层的平均值
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if(root==NULL) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size())
        {
            int len=q.size();
            double sum=0;
            for(int i=0;i<len;i++)
            {
                root=q.front();
                q.pop();
                sum+=root->val;
                if(root->left) q.push(root->left);
                if(root->right) q.push(root->right);
            }
            res.push_back(sum/len);
        }
        return res;
    }
};
```
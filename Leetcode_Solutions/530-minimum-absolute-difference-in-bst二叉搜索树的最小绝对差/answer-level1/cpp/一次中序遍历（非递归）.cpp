# 由二叉搜索树的性质可知，最小绝对差为中序遍历相邻两节点的最小绝对差
1. 中序遍历二叉搜索树，并计算当前节点与前一节点的绝对差
2. 若当前绝对差值(temp)小于min则更新min
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
    int getMinimumDifference(TreeNode* root) {
        if(root==NULL) return -1;
        if(root->left==NULL&&root->right==NULL) return -1;
        stack<TreeNode*> s;
        TreeNode* pre=NULL;
        int min=(1<<31)-1;
        while(root||s.size())
        {
            if(root)
            {
                s.push(root);
                root=root->left;
            }
            else
            {
                root=s.top();
                s.pop();
                if(pre)
                {
                    int temp=(root->val>pre->val)?(root->val-pre->val):(pre->val-root->val);
                    min=(min<temp)?min:temp;
                }
                pre=root;
                root=root->right;
            }
        }
        return min;
    }
};
```
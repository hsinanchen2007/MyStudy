### 解题思路
此处撰写解题思路

### 代码

```cpp
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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int deep=0;
        while(!q.empty()){
            deep++;
            int len=q.size();
            while(len--){
                TreeNode* p=q.front();
                q.pop();
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }
        }
        return deep;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;//极限考虑当为空节点时候，自然是平衡的，所以返回true
        return (abs(maxDepth(root->left)-maxDepth(root->right))<2)&&isBalanced(root->left)&&isBalanced(root->right);//平衡条件：当前节点左右子树平衡，且，其他每个节点的左右树也平衡
    }
};











```
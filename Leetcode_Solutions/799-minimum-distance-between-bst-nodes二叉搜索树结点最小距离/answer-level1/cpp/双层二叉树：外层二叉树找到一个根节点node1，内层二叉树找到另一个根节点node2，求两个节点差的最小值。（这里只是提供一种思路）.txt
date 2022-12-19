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
    // 函数1：从当前根节点开始，到任意节点结束
    void preAccess1(TreeNode* root, int node1, int & min)
    {
        if(root == NULL) return;
        int node2 = root->val;
        if(node1 != node2 && abs(node1 - node2) < min)
            min = abs(node1 - node2);
        preAccess1(root->left, node1, min);
        preAccess1(root->right, node1, min);
    }
    
    // 函数2：找到一个根节点，执行函数1操作
    void preAccess2(TreeNode* root, int & min)
    {
        if(root == NULL) return;
        int node1 = root->val;
        preAccess1(root, node1, min);
        preAccess2(root->left, min);
        preAccess2(root->right, min);
    }
    
    int minDiffInBST(TreeNode* root) {
        int min = 2147483647;
        preAccess2(root, min);
        return min;    
    }

};
```
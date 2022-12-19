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
    void preAccess1(TreeNode* root,int sum1, int sum2, int & cnt)
    {
        if(root == NULL) return;
        sum1 += root->val;
        if(sum1 == sum2)
            cnt++;
        preAccess1(root->left, sum1, sum2, cnt);
        preAccess1(root->right, sum1, sum2, cnt);
    }
    
    // 函数2：找到一个根节点，执行函数1操作
    void preAccess2(TreeNode* root, int sum, int & cnt)
    {
        if(root == NULL) return;
        preAccess1(root, 0, sum, cnt);
        preAccess2(root->left, sum, cnt);
        preAccess2(root->right, sum, cnt);
    }
    
    int pathSum(TreeNode* root, int sum) {
        int cnt = 0;
        preAccess2(root, sum, cnt);
        return cnt;        
    }
};
```
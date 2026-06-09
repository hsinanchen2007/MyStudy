这道题和 124. 二叉树中的最大路径和 有异曲同工之妙，都是定义一个全局变量，然后在另一个函数中利用递归不断更新全局变量的值，这样得到的全局值是最终答案。

为此我们定义helper(TreeNode* root,int& res)代表以当前节点root为根节点，得到的整个二叉树的和，递归更新res值将得到整个二叉树的坡度，实现如下：

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
    int findTilt(TreeNode* root) {
        int res=0;
        helper(root,res);
        return res;
    }
    int helper(TreeNode* root,int& res){
        if(!root) return 0;
        int left=helper(root->left,res);
        int right=helper(root->right,res);
        res+=abs(left-right);
        return left+right+root->val;
    }
};
```
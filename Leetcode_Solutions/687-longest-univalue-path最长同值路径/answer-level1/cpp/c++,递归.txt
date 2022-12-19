### 解题思路
递归遍历所有节点，用ans记录最大值
与 124.二叉树最大路径和 有相似之处
以下是我的代码，同样是递归
https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/solution/cdi-gui-by-zan-wu-ni-cheng-5/

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
public:
int ans=0x80000000;
int func(TreeNode* root){
    int vl=0,vr=0;
    if(root->left){
        if(root->left->val==root->val)vl=func(root->left)+1;
        else func(root->left);
    }
    if(root->right){
        if(root->right->val==root->val)vr=func(root->right)+1;
        else func(root->right);
    }
    ans=max(ans,vr+vl);
    return max(vr,vl);
}
    int longestUnivaluePath(TreeNode* root) {
        if(!root)return 0;
        func(root);
        return ans;
    }
};
```
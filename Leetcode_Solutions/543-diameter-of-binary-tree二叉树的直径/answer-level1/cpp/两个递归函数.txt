### 解题思路
有点慢，但比较直观。

使用了两个递归函数：
    ·length(TreeNode* root)：递归得出以该结点为根的树的深度；
    ·traveral(TreeNode* root,int ans)：ans是目前最大的长度，该函数遍历树，即可得到最大长度。

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
    int ans=0;
    int length(TreeNode* root){
        if(!root) return 0;
        return max(length(root->left)+1,length(root->right)+1);
    }
    int traveral(TreeNode* root,int ans){
        if(!root) return ans;
        ans=length(root->left)+length(root->right);
        ans=max(ans,traveral(root->left,ans));
        ans=max(ans,traveral(root->right,ans));
        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        ans= traveral(root,ans );
        return ans;
    }
};
```
- 分治
首先行数显然等于二叉树高度n，列数显然等于高度等于n的满二叉树的节点数即$2^n-1$
根节点的值在当前这层的$start...end$的中间，子节点在下一层的区间$start...(start+end)/2-1$的中间和$(start+end)/2+1...end$的中间，递归即可
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
    vector<vector<string>> printTree(TreeNode* root) {
        int n = deep(root),m = pow(2,n)-1;
        vector<vector<string>>res(n,vector<string>(m));
        dfs(res,root,0,m-1,0);
        return res;
    }
    int deep(TreeNode* root){
        if(!root)return 0;
        int l = deep(root->left);
        int r = deep(root->right);
        return max(l,r)+1;
    }
    void dfs(vector<vector<string>>&res,TreeNode* root,int start,int end,int curdeep){
        if(!root)return ;
        int mid = (start + end ) >> 1;
        if(root->left)dfs(res,root->left,start,mid-1,curdeep+1);
        if(root->right)dfs(res,root->right,mid+1,end,curdeep+1);
        res[curdeep][mid]=to_string(root->val);
    }
};
```
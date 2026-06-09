### 解题思路
分别计算左右的长度，然后挑更大的返回,注意要在递归中舍去一些已经小于0的枝条

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
    int maxh;
    int maxPathSum(TreeNode* root) {
        //if(root==NULL) return 0;
        maxh=root->val;
        max_path(root);
        return maxh;
    }

    int max_path(TreeNode* root){
        if(root==NULL) return 0;
        int cur=root->val;
        int l=max_path(root->left)+cur;
        int r=max_path(root->right)+cur;
        //cout<<"root"<<root->val<<endl;
        //cout<<"left:"<<l<<" "<<"right"<<r<<endl;
        if(l>maxh) maxh=l;
        if(r>maxh) maxh=r;
        if(l+r-cur>maxh) maxh=l+r-cur;
        //加上这个是因为有的防止每次计算最大路径都必须包括叶结点(对于已经小于0的分支可以直接抛弃)
        if(l<0&&r<0) return 0;
        else return max(l,r);
    }
};
```
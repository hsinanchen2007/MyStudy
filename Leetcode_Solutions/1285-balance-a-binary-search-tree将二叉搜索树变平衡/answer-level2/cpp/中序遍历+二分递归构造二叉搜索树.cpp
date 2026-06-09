今天自己开了场虚拟做了一下，刚看到这题，愣了一下，leetcode水平这么高了？Medium都要用AVL了。。。然后 看通过了1000个人。。。
想了一下不可能。，
然后发现是个沙比题。。

先dfs一遍求得顺序数组。然后二分递归构造就可以了。。唉，太久不写题了。。
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
    int a[50050];
    int al=0;
    TreeNode* balanceBST(TreeNode* root) {
        dfs(root);
        TreeNode *nroot=new TreeNode(1);
        int cnt=0;
        dfs1(nroot,1,al,cnt);
        return nroot;
    }
    void dfs(TreeNode* p){
        if(p==NULL)return;
        dfs(p->left);
        a[++al]=p->val;
        dfs(p->right);
    }
    void dfs1(TreeNode*p,int l,int r,int &cnt){
        if(l==r){
           // cnt++;
            p->val=a[l];
            return ;
        }
        int mid =(l+r+1)>>1;
        p->left=new TreeNode(1);
        dfs1(p->left,l,mid-1,cnt);
        p->val=a[mid];
        if(mid+1<=r){
             p->right=new TreeNode(1);
             dfs1(p->right,mid+1,r,cnt);
        }
      
    }
};
```

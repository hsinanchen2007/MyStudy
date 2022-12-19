##### 暴力
对于任意的二叉树均可
```cpp
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr)return nullptr;
        if(root==p) return p;
        else if(root==q)return q;
        TreeNode* l = lowestCommonAncestor(root->left,p,q);
        TreeNode* r = lowestCommonAncestor(root->right,p,q);
        if(l==p&&r==q||l==q&&r==p)return root;
        else if(l) return l;
        else if(r) return r;
        else return nullptr;
    }
};
```
##### 性质+递归
```cpp
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int m1=p->val,m2=q->val;
        if(m1<root->val&&m2<root->val)
            return lowestCommonAncestor(root->left,p,q);
        else if(m1>root->val&&m2>root->val)
            return lowestCommonAncestor(root->right,p,q);
        else //(m1<root->val&&m2>root->val)
            return root;
    }
};
```
##### 性质+非递归
```cpp
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int m1=p->val,m2=q->val;
        TreeNode* x = root;
        while(1){
            if(m1<x->val&&m2<x->val)
            x = x->left;
            else if(m1>x->val&&m2>x->val)
            x = x->right;
            else
            break;
        }
        return x;
    }
};
```
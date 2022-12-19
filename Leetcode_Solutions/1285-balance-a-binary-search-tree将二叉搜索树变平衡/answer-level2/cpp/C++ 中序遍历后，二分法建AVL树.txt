因为对STL的操作还不是特别熟悉，因此直接用数组存储了...时间有点慢
```
class Solution {
    int list[10100];
    int cnt;
public:
    TreeNode* balanceBST(TreeNode* root) {
        inOrder(root);
        return find(0,cnt - 1);
    }
    void inOrder(TreeNode* root)
    {
        if(!root) return;
        inOrder(root->left);
        list[cnt++] = root->val;
        inOrder(root->right);
    }
    TreeNode* find(int l,int r)
    {
        if(l > r) return NULL;
        int mid = l + r >> 1;
        TreeNode* t = (TreeNode *)malloc(sizeof(TreeNode));
        t->val = list[mid];
        t->left = find(l,mid-1);
        t->right = find(mid+1,r);
        return t;
    }
};
```

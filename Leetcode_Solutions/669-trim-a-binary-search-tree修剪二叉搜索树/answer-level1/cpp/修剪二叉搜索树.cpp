

```cpp

class Solution {
public:
    //递归法，自上而下
    //返回修建好的二叉树
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(!root)return NULL;

        //不满足条件的，继续查找他的子树
        if(root->val<L)return trimBST(root->right,L,R);
        if(root->val>R)return trimBST(root->left,L,R);

        //满足条件的，链接成树
        root->left=trimBST(root->left,L,R);
        root->right=trimBST(root->right,L,R);
        return root;
    }
};
```
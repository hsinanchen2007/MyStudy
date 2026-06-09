C++中序遍历，遍历到第k小，全局变量a保存数值，跳出函数
```cpp
class Solution {
public:
    int a,n;
    void ss(TreeNode* root){
        if(!root)
            return ;
        ss(root->left);
        if(!n)
            return;
        if(n==1)
            a=root->val;
        n--;
        ss(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        n=k;
        ss(root);
        return a;
    }
};
```
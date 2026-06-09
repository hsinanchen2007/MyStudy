采用二叉树中序遍历，ans作为全局变量，只要有一个结点不满足条件即置为false
```
class Solution {
public:  bool ans;
    int search(TreeNode *root){
        if(root==NULL) return 0;
        int leftv = search(root->left);
        int rightv = search(root->right);
        if(root->left) ++leftv;
        if(root->right) ++rightv;
        if(abs(leftv-rightv)>1) ans=false;
        return max(leftv,rightv);
    }
    bool isBalanced(TreeNode* root) {
        ans=true;
        if( !root||(!root->left&&!root->right) ) return true;
        search(root);
        return ans;
    }
};
```

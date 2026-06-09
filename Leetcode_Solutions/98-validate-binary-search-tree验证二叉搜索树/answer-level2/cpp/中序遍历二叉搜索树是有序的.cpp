
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        vector<int>a;
        inorder(root,a);//中序遍历并返回遍历数列
        for(int i=1;i<a.size();i++){//判断是否有序
            if(a[i]>a[i-1]);
            else return false;
        }
        return true;
    }
    void inorder(TreeNode*root,vector<int>&a){
        if(root==NULL)return;
        inorder(root->left,a);
        a.push_back(root->val);//记录中序遍历序列
        inorder(root->right,a);
    }
    
};
```

与之前求最大深度的时候有点区别就是  当一个子树为空的时候 我们不能使用min()函数来判断 而是直接加上那个为空的部分，因为在求最大深度的时候，为空的那个节点自动被忽略了。
```
class Solution {
public:
    int minDepth(TreeNode* root) {
           int result=0;
        if(root==NULL)
            return result;
        else{
         
            if(root->left!=NULL&&root->right)//左右子树都不为空
                    result= min(minDepth(root->left),minDepth(root->right))+1;
             else if(!root->left)//如果左子树为空 那我们直接使用右子树的深度+1，下面也是同样的道理
                 result=minDepth(root->right)+1;
            else if(!root->right)
                result=minDepth(root->left)+1;
        }
        return result;
    }
};
```

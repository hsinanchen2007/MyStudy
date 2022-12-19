看到很多都是java和python的题解代码，就上传一个C++的代码。
递归实现，效率中上，抛砖引玉。
```
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        int numLeft = 0;
        if(root->left){
            numLeft = numDeepth(root->left);
        }
        int numRight = 0;
        if(root->right){
            numRight = numDeepth(root->right);
        }
        if(numLeft == numRight || numLeft+1 == numRight || numRight + 1 == numLeft){
            return isBalanced(root->left) && isBalanced(root->right);
        }
        else{
            return false;
        }
    }
    
    int numDeepth(TreeNode* root){
        int maxLeft=0;
        int maxRight=0;
        if(root->left){
            maxLeft = numDeepth(root->left);
        }
        if(root->right){
            maxRight =  numDeepth(root->right);
        }
        if(maxLeft+maxRight == 0){
            return 1;
    }
        if(maxLeft >=maxRight){
            return maxLeft+1;
        }
        else{
            return maxRight+1;
        }
    }
};
```


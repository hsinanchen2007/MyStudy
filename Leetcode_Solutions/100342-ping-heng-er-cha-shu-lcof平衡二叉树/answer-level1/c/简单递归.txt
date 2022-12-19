### 解题思路
![image.png](https://pic.leetcode-cn.com/cf51f0f65faebd99a0c25c4d30129b47264fc0e27e255422d92fcabfe519e182-image.png)
此处撰写解题思路

### 代码

```c
bool isBalanced(struct TreeNode* root){
    if(root == NULL)
    {
        return true;
    }
    if(isBalanced( root->right)==true && isBalanced( root->left)==true) 
    {
        int r = root->right?root->right->val:0;
        int l = root->left?root->left->val:0;
        root->val = (r > l? r : l)+1;
        if(r-l>1 || r-l<-1)
            return false;
        return true; 
    }   
    else
        return false;
}
```
### 解题思路
![图片.png](https://pic.leetcode-cn.com/1167335e9c11fefb3da1c9d17691fb2c5e03713dad2b28df8408b71bb0cc207f-%E5%9B%BE%E7%89%87.png)


### 代码

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int _caculate(struct TreeNode* root){
    if(root==NULL){
        return 0;
    }
    int left=_caculate(root->left);
    int right=_caculate(root->right);
    if(left!=-1&&right!=-1&&abs(left-right)<2){
        if(left>right){
            return left+1;
        }else{
            return right+1;
        }
    }else{
        return -1;
    }
}

bool isBalanced(struct TreeNode* root){
    int res=_caculate(root);
    if(res==-1){
        return false;
    }else{
        return true;
    }
}
```
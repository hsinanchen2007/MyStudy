### 解题思路
![图片.png](https://pic.leetcode-cn.com/76bb576b1e937f020a892110b575c1059b704bed2b254d9b414feaa11ff507d0-%E5%9B%BE%E7%89%87.png)


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
void _kths(struct TreeNode* root,int *n,int m,int *x){
    if(root==NULL){
        return;
    }
    _kths(root->left,n,m,x);
    (*n)++;
    if(*n==m){
        *x=root->val;
        return;
    }
    if(*n>m){
        return;
    }
    _kths(root->right,n,m,x);
}
int kthSmallest(struct TreeNode* root, int k){
    int n=0;
    int x=0;
    _kths(root,&n,k,&x);
    return x;
}


```
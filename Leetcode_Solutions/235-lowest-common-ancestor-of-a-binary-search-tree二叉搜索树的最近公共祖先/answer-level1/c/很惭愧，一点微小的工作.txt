### 解题思路
![图片.png](https://pic.leetcode-cn.com/e78698911142b958f8b2893505f1efbed803214552287272e677193eb1736445-%E5%9B%BE%E7%89%87.png)

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
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if(root==NULL){
        return NULL;
    }
    if(root==p||root==q){
        return root;
    }
    struct TreeNode*right,*left;
    //if(root->left!=NULL){
    left=lowestCommonAncestor(root->left,p,q);//}
    //if(root->right!=NULL){
    right=lowestCommonAncestor(root->right,p,q);//}
    if(left!=NULL&&right!=NULL){
        return root;
    }else if(left==NULL&&right){
        return right;
    }else if(left&&right==NULL){
        return left;
    }else{
        return NULL;
    }
}
```
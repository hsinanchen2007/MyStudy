### 解题思路
三种情况：
1、NULL return 0
2、只有一个根结点  return 0
3、多于一个结点 return max-2（很蹩脚，总是多两个）
有更好方法可以把三种情况统一起来，参考下其他同学的吧

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

int func(struct TreeNode* root,int *max){
    if(root==NULL){
        return 0;
    }
    int left=func(root->left,max)+1;
    int right=func(root->right,max)+1;
    if((*max)<(left+right)) *max=right+left;
    return left>right?left:right;
}
int diameterOfBinaryTree(struct TreeNode* root){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL&&root->right==NULL){
        return 0; 
    }
    int max=0;
    func(root,&max);
    return max-2;
}
```
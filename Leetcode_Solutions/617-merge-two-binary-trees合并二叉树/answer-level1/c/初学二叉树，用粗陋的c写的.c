### 解题思路
今天第一天学习二叉树，晚上来做道题目巩固一下。递归还是挺难理解的，本题再刚开始做的时候毫无思路，课上讲的虽然听懂了，但是自己写还是好有难度。递归首先需要弄懂返回的东西到底是啥。本题返回的是一个指向TreeNode的指针。刚开始写觉得把t2赋值给t1会改变t1本身，所以用了一个新的t来存t1+t2的值。

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


struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2){
    if(t1 && t2){
         struct TreeNode* t;
         t=(struct TreeNode*)malloc(sizeof(struct TreeNode));
         t->val=t1->val+t2->val;
         t->left=mergeTrees(t1->left,t2->left);
         t->right=mergeTrees(t1->right,t2->right);
         return t;
    }
    if(t1==NULL){
         return t2;
    }
    if(t2==NULL){
         return t1;
    }
    if(!t1 && !t2){
        return NULL;
    }
    return 0;
}
```
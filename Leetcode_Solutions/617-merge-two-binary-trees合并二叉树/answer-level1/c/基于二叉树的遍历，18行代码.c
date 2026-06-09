### 解题思路
![图片.png](https://pic.leetcode-cn.com/d9fe25468fa23dbad2cbe07dda485f4b216f951ec2cab87d4ab4bf36a624cd08-%E5%9B%BE%E7%89%87.png)


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
    if(t1==NULL&&t2!=NULL){
        return t2;
    }
    if(t2==NULL&&t1!=NULL){
        return t1;
    }
    if(t1==NULL&&t2==NULL){
        return NULL;
    }
    if(t1!=NULL&&t2!=NULL){
        t1->val=t1->val+t2->val;
    }
    t1->left=mergeTrees(t1->left,t2->left);
    t1->right=mergeTrees(t1->right,t2->right);
    return t1;
}
```
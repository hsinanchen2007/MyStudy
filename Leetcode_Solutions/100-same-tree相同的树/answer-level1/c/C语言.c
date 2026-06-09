### 解题思路
![image.png](https://pic.leetcode-cn.com/5ba6ab18bb1965ccb0022619a9f60dfb48566df367f41981a8754eae14aa2fa2-image.png)



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


bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if(p == NULL && q == NULL) return true;
    if(p == NULL || q == NULL) return false;
    return (p->val == q->val) && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    
}
```
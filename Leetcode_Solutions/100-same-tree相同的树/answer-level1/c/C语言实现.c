### 解题思路
考虑各种异常：
1、不同时为NULL， 返回false
2、同时为空，返回true
3、不同时为空，值若不同，返回false
4、递归进行左右子树判断

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

    // One tree is NULL, the other is not NULL
    if ((p != q) && ((p == NULL) || (q == NULL))) {
        return false;
    }

    // All are NULL
    if (p == NULL) {
        return true;
    }

    // All trees are not null
    // compare their val
    if (p->val != q->val) {
        return false;
    }

    // compare their children    
    if (isSameTree(p->left, q->left) && isSameTree(p->right, q->right)) {
        return true;
    }

    return false;
}
```
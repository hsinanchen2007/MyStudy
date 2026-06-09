### 解题思路
直接判断，没用用什么技巧
执行用时0ms
内存消耗5.5MB
击败100%
![QQ图片20200327024313.png](https://pic.leetcode-cn.com/eb8c8eb0310b9a85257f0af7f0d9505639536c6a7cbdbdba5d656b9d4ad77879-QQ%E5%9B%BE%E7%89%8720200327024313.png)

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
    if (p == NULL && q == NULL) {
        return true;
    } else if (p== NULL || q== NULL) {
        return false;
    }
    if (p != NULL && q != NULL) {
        if (p->val != q->val) {
            return false;
        }
    }
    if (((p->left == NULL)&&(q->left != NULL))||
        ((p->left != NULL)&&(q->left == NULL))||
        ((p->right == NULL)&&(q->right != NULL))||
        ((p->right != NULL)&&(q->right == NULL))) {
        return false;
    }
    if ((p->left == NULL)&&(q->left == NULL) ||
        (isSameTree(p->left, q->left) == true)) {
        if (((p->right == NULL)&&(q->right == NULL)) ||
            (isSameTree(p->right, q->right) == true)) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}
```
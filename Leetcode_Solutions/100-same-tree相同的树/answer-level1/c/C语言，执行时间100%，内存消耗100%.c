### 解题思路
此处撰写解题思路

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

void compareTree(struct TreeNode* p, struct TreeNode* q, bool* result){
    // 到树的末端时停止递归
    if (p == NULL && q == NULL) {
        return ;
    }
    
    if (p != NULL && q != NULL) { // 如果没有出现一个节点为空另一个不为空，则继续递归
        if (p->val == q->val) {
            compareTree(p->left, q->left, result);
            compareTree(p->right, q->right, result);
        } else {
            *result = false;
            return;
        }
    } else { // 如果一个为空，另一个不为空，则返回错误
        *result = false;
        return;
    }

}

bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    bool result = true;
    compareTree(p, q, &result);
    return result;
}
```
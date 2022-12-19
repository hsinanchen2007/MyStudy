### 解题思路
通过前序遍历记录每一个遇到的node，然后加在链表的左侧。等到遍历结束，将所有的左侧的链表节点移到右侧。

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

struct TreeNode* next = NULL;

void f(struct TreeNode* root)
{
    if (root == NULL) return;
    
    if (next == NULL) next = root;
    else {
        next->left = root;
        next = next->left;
    }
    f(root->left);
    f(root->right);
}
void flatten(struct TreeNode* root){
    if (root == NULL) return;
    f(root);
    
    struct TreeNode* node = root->left;
    struct TreeNode* tail = root;
    
    while (node != NULL) {
        tail->right = node;
        node = node->left;
        tail->left = NULL;
        tail = tail->right;
    }
    
}
```
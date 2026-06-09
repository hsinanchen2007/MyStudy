### 解题思路
纯C 递归

### 代码

```c
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */

struct Node* connect(struct Node* root) {
	if (NULL == root || (NULL == root->left && NULL == root->right))
    {
        return root;
    }

    root->left->next = root->right;

    if (root->next)
    {
        root->right->next = root->next->left;
    }

    connect(root->left);
    connect(root->right);

    return root;
}
```
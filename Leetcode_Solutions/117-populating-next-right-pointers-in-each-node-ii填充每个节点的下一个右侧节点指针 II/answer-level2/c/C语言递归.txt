```
struct Node *GetNextNoNullNode(struct Node *root)
{
    while (root->next != NULL) {
        if (root->next->left != NULL) {
            return root->next->left;
        }
        if (root->next->right != NULL) {
            return root->next->right;
        }
        root = root->next;
    }
    return NULL;
}
struct Node *connect(struct Node *root)
{
    if (root == NULL) {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL) {
        return root;
    }

    if (root->left != NULL && root->right != NULL) {
        root->left->next = root->right;
        root->right->next = GetNextNoNullNode(root);
    } else if(root->left != NULL) {
        root->left->next = GetNextNoNullNode(root);
    } else if (root->right != NULL) {
        root->right->next = GetNextNoNullNode(root);
    }

    root->right = connect(root->right);
    root->left = connect(root->left);

    return root;
}
```

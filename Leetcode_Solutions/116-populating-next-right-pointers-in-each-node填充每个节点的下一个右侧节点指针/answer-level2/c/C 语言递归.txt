```
void Trav(struct Node *root)
{
    if (root->left == NULL && root->right == NULL) {
        return;
    }
    root->left->next = root->right;
    if (root->next == NULL) {
        root->right->next = NULL;
    } else {
        root->right->next = root->next->left;
    }

    Trav(root->left);
    Trav(root->right);
}

struct Node* connect(struct Node* root) {
    if (root == NULL) {
        return NULL;
    }

    root->next = NULL;
    Trav(root);

    return root;
}
```

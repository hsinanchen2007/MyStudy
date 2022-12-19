C语言，标准的中序遍历，双百通过。代码如下所示，没啥特殊点。
```
struct TreeNode* dummyHead;
struct TreeNode* prevNode;

void visit(struct TreeNode* root)
{
    if ((dummyHead == NULL) && (root->left == NULL)) {
        dummyHead = root;
        prevNode = dummyHead;
        prevNode->left = NULL;
        prevNode->right = NULL;
    } else if (dummyHead) {
        prevNode->left = NULL;
        prevNode->right = root;
        root->left = NULL;
        root->right = NULL;
        prevNode = root;
    }
}

void inOrder(struct TreeNode* root)
{
    if (root == NULL) {
        return;
    }

    struct TreeNode* leftNode = root->left;
    struct TreeNode* rightNode = root->right;

    inOrder(leftNode);
    visit(root);
    inOrder(rightNode);
}


struct TreeNode* convertBiNode(struct TreeNode* root){
    dummyHead = NULL;
    inOrder(root);
    return dummyHead;

}
```

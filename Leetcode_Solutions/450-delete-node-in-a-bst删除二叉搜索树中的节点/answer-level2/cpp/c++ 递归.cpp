递归删除，利用TreeNode**的方式搜索，以避免对节点是否是root节点的情况进行讨论。
```
class Solution {
public:
    TreeNode** searchNode(TreeNode** root, int key) {
        if ((*root) == NULL)
            return NULL;
        if ((*root)->val == key)
            return root;
        if ((*root)->val < key)
            return searchNode(&(*root)->right, key);
        return searchNode(&(*root)->left, key);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode** pnode = searchNode(&root, key);
        if (pnode == NULL)
            return root;
        if ((*pnode)->left == NULL && (*pnode)->right == NULL) {
            (*pnode) = NULL;
            return root;
        }
        if ((*pnode)->right == NULL) {
            (*pnode) = (*pnode)->left;
            return root;
        }
        TreeNode** next = &(*pnode)->right;
        while ((*next) != NULL && (*next)->left != NULL) {
            next = &(*next)->left;
        }
        (*pnode)->val = (*next)->val;
        *next = deleteNode((*next), (*next)->val);
        return root;
    }
};
```

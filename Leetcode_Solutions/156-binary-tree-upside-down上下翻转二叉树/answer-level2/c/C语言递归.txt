1、先遍历左子树，找到新的跟节点。
2、返回跟节点，其左子树为原节点的右子树，右子树为原来的父节点，并返回右子树。
```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode BTree;
BTree *g_newTreeRoot = NULL;

BTree *CreatNode(int val)
{
    BTree *Node = (BTree *)malloc(sizeof(BTree));
    Node->left = NULL;
    Node->right = NULL;
    Node->val = val;
    return Node;
}

BTree *Dfs(struct TreeNode* Node) 
{
    if (Node == NULL) {
        return NULL;
    }

    BTree *tmpNode = Dfs(Node->left);

    if (tmpNode == NULL){
        /* 左子树为空，说明是新的根节点 */
        BTree *newNode = CreatNode(Node->val);
        g_newTreeRoot = newNode;
        return newNode;
    } else {
        tmpNode->right = CreatNode(Node->val);
        /* 这里注意判空 */
        if (Node->right != NULL) {
            tmpNode->left = CreatNode(Node->right->val);
        }
    }

    return tmpNode->right;
}
struct TreeNode* upsideDownBinaryTree(struct TreeNode* root){
    g_newTreeRoot = NULL;
    (void)Dfs(root);
    return g_newTreeRoot;
}
```

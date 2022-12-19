### 解题思路
其实思路很简单，先序遍历的第一个元素就是根节点，然后在中序遍历里找到这个节点就可以了
由于C语言的函数是传递指针，所以代码可以很简洁，同时效率很高
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

typedef struct TreeNode *pNode;

pNode buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    if (!preorderSize || !inorderSize) return NULL;
    pNode root = (pNode) malloc(sizeof(struct TreeNode));
    root->val = preorder[0];
    int pos = 0;
    while (inorder[pos] != root->val) ++pos;
    root->left  = buildTree(preorder + 1, pos, inorder, pos);
    root->right = buildTree(preorder + 1 + pos, preorderSize - 1 - pos, inorder + pos + 1, inorderSize - 1 - pos);
    return root;
}
```
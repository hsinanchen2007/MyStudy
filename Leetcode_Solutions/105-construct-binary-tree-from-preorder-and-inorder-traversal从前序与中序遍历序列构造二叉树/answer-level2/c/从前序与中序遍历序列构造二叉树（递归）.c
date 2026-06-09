### 解题思路
方案：理解还原二叉树的过程+细心，在写代码时边界条件要仔细判断
   本题就是根据前序和中序来确定构造二叉树，当前序第一位来确定出跟，然后将中序序列分为左子树成员集合和右子树成员集合，然后计算出前序的左子树成员集合和右子树成员集合，根据集合的长度来计算，然后重复下去，也就是递归，直到左子树成员集合或右子树成员集合的长度变为1的时候，就可以开始构造树节点，然后回溯，就可以生成一颗二叉树了。

### 一代码

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* sloveTree(int* preorder, int preStart, int preEnd, int* inorder, int inStart, int inEnd);
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize);

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    struct TreeNode* root = sloveTree(preorder, 0, preorderSize, inorder, 0, inorderSize);
    return root;
}

struct TreeNode* sloveTree(int* preorder, int preStart, int preEnd, int* inorder, int inStart, int inEnd) {
    if (preStart >= preEnd) {
        return NULL;
    }
    int i = 0;
    for (i = inStart; i < inEnd; i++) {
        if (preorder[preStart] == inorder[i]) {
            break;
        }
    }
    if (inStart >= inEnd) {
        struct TreeNode* node = (struct TreeNode*)calloc(sizeof(struct TreeNode), 1);
        node->val = inorder[inStart];
        return node;
    }
    
    struct TreeNode* parent = (struct TreeNode*)calloc(sizeof(struct TreeNode), 1);
    parent->left = sloveTree(preorder, preStart+1, preStart+1+(i-inStart), inorder, inStart, i);
    parent->right = sloveTree(preorder, preStart+(i-inStart)+1, preEnd, inorder, i+1, inEnd);
    parent->val = preorder[preStart];
    return parent;
}
```
上面写的代码思路不太清晰

```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* sloveTree(int* preorder, int preStart, int preEnd, int* inorder, int inStart, int inEnd);
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize);

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    struct TreeNode* root = sloveTree(preorder, 0, preorderSize, inorder, 0, inorderSize);
    return root;
}

struct TreeNode* sloveTree(int* preorder, int preStart, int preEnd, int* inorder, int inStart, int inEnd) {
    if (preStart >= preEnd || preStart >= preEnd) {
        return NULL;
    }
    int i = 0;
    for (i = inStart; i < inEnd; i++) {
        if (preorder[preStart] == inorder[i]) {
            break;
        }
    }
    struct TreeNode* node = (struct TreeNode*)calloc(sizeof(struct TreeNode), 1);
    node->val = inorder[i];
    node->left = sloveTree(preorder, preStart+1, preStart+1+(i-inStart), inorder, inStart, i);
    node->right = sloveTree(preorder, preStart+(i-inStart)+1, preEnd, inorder, i+1, inEnd);
    return node;
}
```


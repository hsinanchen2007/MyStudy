执行用时 :24 ms, 在所有 C 提交中击败了60.61%的用户
内存消耗 :13.1 MB, 在所有 C 提交中击败了100.00%的用户

解决思路：分而治之
1.通过前序遍历判断出根节点后
2.筛选出根节点左子树和又子树
3.在前序遍历和中序遍历进行切分三部分，根节点，左子树部分和右子树部分
4.左子树部分又可以分出来左子树的前序遍历和中序遍历，右子树也同样
5.依照这种分化思路，将一个大的二叉树，划分成一个小的二叉树，并用递归函数求得二叉树的最终形式
```
struct TreeNode* buildBinaryTree(int* preorderStart, int* preorderEnd, int* inorderStart, int* inorderEnd);

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    if (preorder == NULL || inorder == NULL || preorderSize == 0 || inorderSize != preorderSize) {
        return NULL;
    }
    
    return buildBinaryTree(preorder, preorder + preorderSize - 1, inorder, inorder + inorderSize - 1);
}

struct TreeNode* buildBinaryTree(int* preorderStart, int* preorderEnd, int* inorderStart, int* inorderEnd)
{
    int rootValue = preorderStart[0];
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = rootValue;
    root->left = NULL;
    root->right = NULL;
    
    if (preorderStart == preorderEnd) {
        if (inorderStart == inorderEnd && *preorderStart == *inorderStart) {
            return root;
        } else {
            free(root);
            return NULL;
        }
    }
    
    //构建左子树
    int* rootInorder = inorderStart;
    int inorderLen = inorderEnd - inorderStart;
    while (rootInorder <= inorderEnd && *rootInorder != rootValue) rootInorder++;
    
    if (rootInorder == inorderEnd && *rootInorder != rootValue) {
        free(root);
        return NULL;
    }
    
    int leftInoderLen = rootInorder - inorderStart;
    int* leftPreorder = preorderStart + leftInoderLen;
    
    if (leftInoderLen > 0) {
        root->left = buildBinaryTree(preorderStart + 1, leftPreorder, inorderStart, rootInorder - 1);
    }
    
//构建右子树
    if (leftInoderLen < inorderLen) {
        root->right = buildBinaryTree(leftPreorder + 1, preorderEnd, rootInorder + 1, inorderEnd);
    }
    
    return root;
}
```

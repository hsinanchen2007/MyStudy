又臭又长的C代码，特点是一次申请够内存，在一维数组中的顺序看上去和前序遍历结果一样。

在一维数组树的存储模式是 {根，{左子树}，{右子树}}，所以只要从遍历结果中自树顶向底找出每一层的左右子树大小就可以直接定位到相应节点在数组中的位置，改造成前序+中序输入的形式也不难

提交了几遍，有时候32ms，有时候24ms，最少的16ms，也不知道应该以谁为准

```
void constructBTree(int* inorder, int* postorder, struct TreeNode* treeBranch, int treeSize);

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize)
{
    if (inorderSize != postorderSize || inorderSize == 0)
        return NULL;
    
    struct TreeNode* treeArray = (struct TreeNode*)malloc(inorderSize * sizeof(struct TreeNode));
    constructBTree(inorder, postorder, treeArray, inorderSize);
    
    return treeArray;
}

void __attribute__((fastcall)) constructBTree(int* inorder, int* postorder, struct TreeNode* treeBranch, int treeSize)
{    
    int rootVal = postorder[treeSize - 1];
    treeBranch->val = rootVal;
    
    int rootPos = 0;
    for( ; rootPos < treeSize; rootPos++)
    {
        if (inorder[rootPos] == rootVal)
            break;
    }
    int leftBranch_size = rootPos;
    int rightBranch_size = treeSize - leftBranch_size - 1;
    treeBranch->left = treeBranch->right = NULL;
    
    if (leftBranch_size > 0)
    {
        treeBranch->left = treeBranch + 1;
        constructBTree(inorder, postorder, treeBranch->left, leftBranch_size);
    }
    
    if (rightBranch_size > 0)
    {
        treeBranch->right = treeBranch + leftBranch_size + 1;
        constructBTree(inorder + leftBranch_size + 1, postorder + leftBranch_size, treeBranch->right, rightBranch_size);
    }  
}
```
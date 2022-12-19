参考@元仲辛 简单易懂版题解，花了几幅图才理解。
根据后序遍历和中序遍历的性质，先从后序遍历中找到最后一个节点，即根节点，值为val，然后再中序遍历中找到val的下标i,可得val的左子树在中序遍历中的位置为0~i-1，val的右子树在中序遍历中的位置为i+1 ~ inEnd。这时候就可以递归了。咋递归呢，分别找val的右子树根节点right和左子树的根节点left。找到后，组合起来即可。一开始不理解为什么后序遍历中最后一个元素为根节点，可能第一个根节点比较容易看出来，这一点通过画个图比较下就容易看出来了。后序遍历中从后往前，依次是根节点，根节点右子树的根节点，根节点右子树的右子树的根节点....然后才是右子树*n的左子树根节点。我们逐个查找子树根节点，最终组合成得到我们需要的图。可以观察下下图中后序遍历每个元素在原始树中的位置，根节点，根节点的右子树根节点，孙右节点，最终才是左子树根节点。这个顺序也决定了我们递归时候的顺序，先右子树再左子树，可以结合c代码一起观察下：
![capture_20190820193850401.bmp](https://pic.leetcode-cn.com/e142c2a8f03bda42eacd8d2935798b8bf9761ba823bd3b90b6a2af43e1c94e85-capture_20190820193850401.bmp)

```
struct TreeNode *findSubTree(int* inorder, int* postorder, int *postEnd, int inStart, int inEnd)
{
    int val, i;
    struct TreeNode *root, *left, *right;
    
    if (inStart > inEnd)
        return NULL;
    
    //取出子树根节点
    val = postorder[*postEnd];
    
    //指向下一个子树的根节点
    *postEnd = *postEnd - 1;
    
    //中序遍历查找根节点所在位置
    for (i = 0; i <= inEnd; i++)
        if (inorder[i] == val)
            break;
    
    //继续查找root的右子树和左子树，顺序不能搞错
    right = findSubTree(inorder, postorder, postEnd, i + 1, inEnd);
    left = findSubTree(inorder, postorder, postEnd, inStart, i - 1);
    
    //组合子树
    root = (struct TreeNode *)calloc(1, sizeof(struct TreeNode));
    root->val = val;
    root->left = left;
    root->right = right;
    return root;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){
    int postEnd = postorderSize - 1;
    return findSubTree(inorder, postorder, &postEnd, 0, inorderSize - 1);
}
```

```
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){
    if (inorderSize == 0)   // 长度为空
           return NULL;
    int i = 0;
    // 根据postorder的最后一个值(树根),在inorder序列中从后往前找到树根的位置
    while (inorder[inorderSize - 1 - i] != postorder[postorderSize - 1])
        ++i;
    assert(i >= 0);
    // 生成树根节点
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = postorder[postorderSize - 1];
    // 由于inoder从最后一个元素往前移动了i次,设i所指位置前面有x个元素(不包括i所指元素),x + i = inorderSize - 1;
    // 所以x = inoderSize - i - 1;
    // 不管怎样新的postorderSize = 新的inorderSize = x
    root->left = buildTree(inorder, inorderSize - i - 1, postorder, inorderSize - i - 1);
    // 新的inorder要移动到i所指位置后一个,所以新的inorder位置需要移动x + 1次，为inorder + inorderSize - i;
    // 由于树根位置是inorder往前移动i次所得到的，所以树根的右边还有i个元素
    // 不管怎样新的postorderSize = 新的inorderSize = i
    // 假设新的postorder需要移动y次,所以y + i + 1 = 原来的postorderSize
    // (注意最后一个元素是树根，需要加1，才等于原来的postorderSize)，所以y = postorderSize - i - 1;
    // 所以新的postorder = 原来的postorder + y = 原来的postorder + postorderSize - i - 1
    root->right = buildTree(inorder + inorderSize - i, i, postorder + postorderSize - i - 1, i);
    return root;
}
```

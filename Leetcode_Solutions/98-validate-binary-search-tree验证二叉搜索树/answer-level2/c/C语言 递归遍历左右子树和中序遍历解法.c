解法1：根据二叉树性质，节点的左子树全部小于父节点，节点右子树全部大于父节点。如果这样简单和父节点比较特别容易出错。因此需要保存节点的上下边界。
节点只需和上下界比较即可。
对于根节点而言，上下界同为NULL，
左节点的上界为父节点，下界继承父节点NULL;
右节点的下界为父节点，上界继承自父节点NULL; 使用指针可以避免考虑INT_MIN, INT_MAX整型边界问题。
```
bool checkBST(struct TreeNode *node, int *upper, int *lower)
{
    int ret = 1;
    if (upper && node->val >= *upper)
        return 0;
    if (lower && node->val <= *lower)
        return 0;
    if (node->left)
        ret *= checkBST(node->left, &node->val, lower);
    if (node->right)
        ret *= checkBST(node->right, upper, &node->val);
        
    return ret;
}
bool isValidBST(struct TreeNode* root){
    int ret = 1, *prev = NULL;
    if (!root)  return 1;
    //根节点上下界为NULL;
    return checkBST(root, NULL, NULL);    
}
```

解法2：根据二叉树性质，二叉树的中序遍历得到有序序列，因此可以中序遍历二叉树，对于每一个节点，保存其前继节点的值，然后和当前节点比较即可。
```
//中序遍历
bool inOrderTraverse(struct TreeNode* root, int **prev)
{
    int ret = 1;
    //遍历左子树
    if (root->left)
        if (inOrderTraverse(root->left, prev) == 0)
            return 0;
    //中间节点
    if (*prev)
        if (root->val <= *(*prev))
            return 0;
    //更新前继节点
    *prev = &root->val;
    
    //遍历右子树
    if (root->right)
        if (inOrderTraverse(root->right, prev) == 0)
            return 0;
    return ret;
}

bool isValidBST(struct TreeNode* root){
    int ret = 1, *prev = NULL;
    //特殊情况处理
    if (!root)  return 1;
    //解法2
    return inOrderTraverse(root, &prev);
}
```



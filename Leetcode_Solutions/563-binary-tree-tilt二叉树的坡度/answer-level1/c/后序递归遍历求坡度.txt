```c
/**
 * 后序递归遍历二叉树，每个结点的坡度等于左子树的结点之和和右子树结点之和的差的绝对值
 * 通过遍历累加所有结点的坡度
 **/
int traverse(struct TreeNode *root, int *tilt)
{
    int l, r;
    if (root)
    {
        l = traverse(root->left, tilt);     //左子树和
        r = traverse(root->right, tilt);    //右子树和
        *tilt += abs(l - r);        //求坡度
        return l + r + root->val;
    }
    return 0;
}

int findTilt(struct TreeNode *root)
{
    int tilt = 0;
    traverse(root, &tilt);
    return tilt;
}
```

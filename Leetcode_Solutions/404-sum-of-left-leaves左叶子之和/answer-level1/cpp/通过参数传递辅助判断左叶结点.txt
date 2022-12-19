判断叶结点比较简单，只需要看有没有子节点即可，但是判断左叶结点就比较麻烦了，因为递归本身是没有状态的。我看大部分人的解决方案是在父结点进行处理，类似于这样：

```c++
return root->left->val;
```

但是我们可以利用参数传递来赋予递归状态，这样就可以用同样的方式处理每一个结点，而不是对叶结点特殊化。解法如下：

```c++
/**
 * ------result------
 * memory: 13.3 MB (94.48%)
 * speed:  0 ms    (100%)
 */
int sumOfLeftLeaves(TreeNode *root, bool isLeft)
{
    if (root)
    {
        // 左叶节点
        if (isLeft && !root->left && !root->right)
        {
            return root->val;
        }
        else
        {
            return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false);
        }
    }
    return 0;
}

int sumOfLeftLeaves(TreeNode *root)
{
    return sumOfLeftLeaves(root, false);
}
```


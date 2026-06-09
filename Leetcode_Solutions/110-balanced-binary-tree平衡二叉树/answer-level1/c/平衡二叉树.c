### 解题思路
学习一下大佬的提前阻断法。

### 代码

```c

int judge(struct TreeNode* t)
{
    if(!t)
        return 0;
    int l = judge(t->left);
    if(l == -1)
        return -1;
    int r = judge(t->right);
    if(r == -1)
        return -1;
    if(abs(l - r) < 2)
        return (l > r ? l : r) + 1;
    else
        return -1;
}

bool isBalanced(struct TreeNode* root){
    return judge(root) != -1;
}
```
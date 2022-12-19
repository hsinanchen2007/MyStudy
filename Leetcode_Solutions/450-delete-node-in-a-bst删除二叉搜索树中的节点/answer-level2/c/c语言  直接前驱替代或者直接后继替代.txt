删除一个节点后要保持原有二叉树性质，根据节点自身的情况有三种情况需要处理
1. 如果节点没有左右子树，则可以直接删除。
2. 如果节点只有左子树或者右子树，则可以直接让子树替代自己。
3. 如果同时存在左右节点，我们知道中序遍历二叉树得到有序数列，这时候有两种操作方式，一种是使用直接前驱替代待删节点，一种是使用直接后继替代待删节点。两种方式操作逻辑一致，仅仅方向不同。
3.1 设待删节点为delte, 如果采用直接前驱替代，这时候搜索节点左子树最右边的点s(s没有右子树),这时候有两种情况，一种是s本身就是待删节点的左子树，即s的父节点等于delte，这时候令
```
delte->left = s->left;delte->val = s->val;即可。
```
如果s的父节点p不等于delte，这时候需要将s的左子树变为p的右子树即可。
整个代码也比较简单理解：
```
//直接前驱替代
p = delte; s = delte->left;
while (s->right){p = s; s = s->right;}
dlete->val = s->val;
if (p == delte) delte->left = s->left;
else p->right = s->left;
free(s);
```
如果使用直接后继替代delte的话，这时候是搜索delte的右子树中最左边的元素s，同样存在两种情况，s的父节点p等于delte或者不等于，处理上和直接前驱类似。
```
//直接后继替代
p = delte; s = delte->right;
while (s->left){p = s; s = s->left;}
dlete->val = s->val;
if (p == delte) delte->right = s->right;
else p->left = s->right;
free(s);
```
下面是直接后继替代的代码：
```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* deleteBST(struct TreeNode* delte)
{
    struct TreeNode *p, *t;
    
    if (!delte->right)
    {
        //只有左孩子的情况
        t = delte; delte = delte->left;
    }
    else if (!delte->left)
    {
        //只有右孩子的情况        
        t = delte; delte = delte->right; 
    }
    else
    {
        //左右孩子都有，从右子树搜索其直接后继，即最左边的元素
        p = delte; t = p->right;
        while (t->left){
            p = t; t = t->left;
        }
        delte->val = t->val;
        if (p == delte)
            delte->right = t->right;
        else
            p->left = t->right;
    }
    
    free(t);
    return delte;
}

struct TreeNode* deleteNode(struct TreeNode* root, int key){
    if (!root)  return root;
    
    if (root->val == key)
        root = deleteBST(root);
    else if (root->val > key)
        root->left = deleteNode(root->left, key);
    else
        root->right = deleteNode(root->right, key);
    
    return root;
}
```

参考资料：

1. 数据结构 : C语言版/ 严蔚敏，吴伟民编著

2. 算法导论

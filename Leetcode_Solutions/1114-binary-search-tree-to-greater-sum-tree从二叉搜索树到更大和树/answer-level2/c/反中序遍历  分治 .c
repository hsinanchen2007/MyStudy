执行用时 :0 ms, 在所有 C 提交中击败了100.00%的用户
内存消耗 :5.7 MB, 在所有 C 提交中击败了100.00%的用户

# 解题思路：
对于二叉搜索树，右子树均大于跟节点，左子树均小于跟节点。

以简化模型为例：
----------Parent
---------/-------\\
------Left-------Right
------/----\\-------/-----\\
---LL---LR----RL----RR

右侧的逻辑相对简单：
P->val += sum(Right)
再分析左侧逻辑：
Left->val = Left->val + sum(LR) **+ P->val**
可以看到左子树跟右子树的区别就是需要把root的值作为一个附加值带入求和运算中，并且要传递到左子树的所有子树里。
再结合分治思想，递归的代码很容易就出来了。

# 代码
```
int TraceTree(struct TreeNode* root, int exVal)
{
    // 对于左子树的root，要把父root的值作为exVal带入，用于累加
    if (!root) {
        return 0;
    } else if ((root->left == NULL) && (root->right == NULL)) {
        root->val += exVal;
        return root->val - exVal;
    }
    root->val += TraceTree(root->right, exVal);
    root->val += exVal;
    return root->val + TraceTree(root->left, root->val) - exVal;
}

struct TreeNode* bstToGst(struct TreeNode* root)\
{
    (void)TraceTree(root, 0);
    return root;
}
```

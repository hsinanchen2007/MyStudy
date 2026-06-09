### 解题思路
此处撰写解题思路
递归解法：因为是前序遍历得到的数组，因此数组第一个元素一定是根节点，第一个元素之后的元素分为两组，分别构成了根节点的子树（有可能为空）。假设数组的索引为 left 到 right，那么preorder[left]就是当前的根节点，从left + 1开始到end，找到第一个比preorder[left]大的元素i, 那么left+1到i-1的元素便是左子树，i到right的元素便是右子树。然后递归该过程即可得到二叉搜索树。
该题要注意的点有两个：
1）二叉搜索树的一个关键性质，一定是 right > node >= left;
2）在left+1和right之间寻找左右子树的分界位置时，不能简单的用 i = (left + 1 + right) / 2,原因就是因为上面第一点。

### 代码

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode *SubTree(int *preorder, int left, int right)
{
    struct TreeNode *node;
    int i;

    if (left > right) {
        return NULL;
    }
    
    node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    memset(node, 0, sizeof(struct TreeNode));
    node->val = *(preorder + left);

    for (i = left + 1; i <= right; ++i) {
        if (preorder[i] > preorder[left]) {
            break;
        }
    }

    node->left = SubTree(preorder, left + 1, i - 1);
    node->right = SubTree(preorder, i, right);

    return node;
}

struct TreeNode* bstFromPreorder(int* preorder, int preorderSize){
    return SubTree(preorder, 0, preorderSize - 1);
}
```
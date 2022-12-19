### 解题思路
以每个节点作为根节点的最大直径，是这个节点的left最大高度 + right的最大高度
每个节点的高度是left + 1 或者right + 1 求最大
2个启示:
1、left和right不一定非要保存到二叉树节点中
2、全局变量的初始化和递归不要搞错

### 代码

```c
/*
以每个节点作为根节点的最大直径，是这个节点的left最大高度 + right的最大高度
每个节点的高度是left + 1 或者right + 1 求最大
2个启示:
1、left和right不一定非要保存到二叉树节点中
2、全局变量的初始化和递归不要搞错
*/

#define MAX(a, b)  ((a) > (b) ? (a) : (b))

static int max = 0;
int dfs(struct TreeNode *root)
{
        int left;
        int right;
        if (!root)
                return 0;
        left = dfs(root->left);
        right = dfs(root->right);
        max = MAX(max, left + right + 1);
        return MAX(left + 1, right + 1);
}

int diameterOfBinaryTree(struct TreeNode *root)
{
        if (!root)
                return 0;
        max = 0;
        dfs(root);
        return max - 1;
}
```
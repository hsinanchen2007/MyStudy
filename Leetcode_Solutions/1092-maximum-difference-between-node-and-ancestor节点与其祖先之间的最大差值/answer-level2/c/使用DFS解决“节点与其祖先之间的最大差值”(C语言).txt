### 解题思路
思路关键在于：将问题转化为当前路径上的最大值和最小值问题。

具体解法上，将最大值、最小值随着DFS参数传递，在叶子节点处统计即可。

![image.png](https://pic.leetcode-cn.com/713505bbfc62c830a018af9a55767080adedb7ef07857b0ba1f698c9583b65e3-image.png)


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

#define MMAX(a, b)        ((a) > (b)? (a) : (b))
#define MMIN(a, b)        ((a) < (b)? (a) : (b))

int max_diff;

void helper(struct TreeNode* root, int max, int min)
{
    max = MMAX(max, root->val);
    min = MMIN(min, root->val);

    if(root->left == NULL && root->right == NULL)
    {
        max_diff = MMAX(max_diff, max - min);
        return;
    }

    if(root->left != NULL)
    {
        helper(root->left, max, min);
    }

    if(root->right != NULL)
    {
        helper(root->right, max, min);
    }
}

//【算法思路】DFS。传递最大最小值，在叶子节点进行统计刷新
int maxAncestorDiff(struct TreeNode* root){
    max_diff = 0;

    helper(root, root->val, root->val);

    return max_diff;
}
```
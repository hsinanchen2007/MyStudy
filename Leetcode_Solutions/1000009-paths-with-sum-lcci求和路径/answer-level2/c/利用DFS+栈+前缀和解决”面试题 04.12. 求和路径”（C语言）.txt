### 解题思路

本质是考察前缀和的题目，结合了栈和DFS的概念。

注意dfs天然保证了栈指针的维护。


![image.png](https://pic.leetcode-cn.com/e48a172ffa092fb483ab4117d47ac78e72ec58d4af372c948081075e88b40454-image.png)


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
#define TREE_LEVEL  10001

int target;
int stk[TREE_LEVEL];

typedef struct TreeNode node_st;

int helper(node_st *root, int ssize, int tsum)
{
    int ret = 0;
    tsum += root->val;
    stk[ssize++] = tsum;

    //计算新生成数据，有多少达成目标的结果
    for(int i = 0; i < ssize - 1; i++)
    {
        if(stk[ssize - 1] - stk[i] == target)
        {
            ret++;
        }
    }

    if(root->left != NULL)
    {
        ret += helper(root->left, ssize, tsum);
    }

    if(root->right != NULL)
    {
        ret += helper(root->right, ssize, tsum);
    }

    return ret;
}

//【算法思路】栈+积分。
int pathSum(struct TreeNode* root, int sum){
    if(root == NULL) {
        return 0;
    }

    target = sum;

    stk[0] = 0;

    int ret = helper(root, 1, 0);

    return ret;
}
```
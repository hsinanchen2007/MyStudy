### 解题思路
此处撰写解题思路
（1）从根节点开始；
（2）从左子树开始；
（3）从右子树开始；
注意：某条路径上找到一条路径之后，再从该节点的左右子孩子遍历，而不能直接返回

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

int myPathSum2(struct TreeNode* root, int sum) 
{
    int cnt = 0;
    if (root == NULL) {
        return cnt;
    }
    sum -= root->val;
    if (sum == 0) {
        cnt++;
    }

    cnt += myPathSum2(root->left, sum);
    cnt += myPathSum2(root->right, sum);

    return cnt;
}

int pathSum(struct TreeNode* root, int sum) {
    if (root == NULL) {
        return 0;
    }

    return myPathSum2(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
}

```




```c

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int g_val = 0;
void myPathSum2(struct TreeNode* root, int sum, int val)
{
    if (root == NULL) {
        return;
    }
    val += root->val;
    if (val == sum) {
        g_val++;
        /* 这里不能直接返回，因为从根节点到叶子结点可能也是一个结果，如：
            [1,-2,-3,1,3,-2,null,-1]
            -1
         */
    }
    myPathSum2(root->left, sum, val);
    myPathSum2(root->right, sum, val);
}

void myPathSum1(struct TreeNode* root, int sum)
{
    if (root == NULL) {
        return;
    }

    myPathSum2(root, sum, 0);
    myPathSum1(root->left, sum);
    myPathSum1(root->right, sum);
}

int pathSum(struct TreeNode* root, int sum){
    
    g_val = 0;

    myPathSum1(root, sum);

    return g_val;
}


```

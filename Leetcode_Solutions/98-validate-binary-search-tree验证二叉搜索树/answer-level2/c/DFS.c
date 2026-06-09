### 解题思路
2个条件：
1）当前节点的左右子树是二叉搜索树；
2）当前节点的值要大于左子树的最大值，同时要小于右子树的最小值

### 代码

```c
int FindMax(struct TreeNode* root)
{
    struct TreeNode *tmp = root;
    while (tmp->right != NULL) {
        tmp = tmp->right;
    }
    return tmp->val;
}

int FindMin(struct TreeNode* root)
{
    struct TreeNode *tmp = root;
    while (tmp->left != NULL) {
        tmp = tmp->left;
    }
    return tmp->val;
}

int dfs(struct TreeNode* root)
{
    if (root == NULL) {
        return 1;
    }
    int leftFlag = dfs(root->left);
    int rightFlag = dfs(root->right);
    if (!leftFlag || !rightFlag) {
        return 0;
    }
    if (root->left != NULL) {
        /* find max */
        int leftMax = FindMax(root->left);
        if (leftMax >= root->val) {
            return 0;
        }
    }
    if (root->right != NULL) {
        /* find min */
        int rightMin = FindMin(root->right);
        if (rightMin <= root->val) {
            return 0;
        }
    }          
    return 1;
}

bool isValidBST(struct TreeNode* root){
    int ret = dfs(root);
    if (ret) {
        return true;
    } else {
        return false;
    }
}
```
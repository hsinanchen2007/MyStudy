### 解题思路
深搜到叶子结点，判断路径数值等于目标值

有个问题是我设置了全局变量g_flag，
在 hasPathSum 函数中如果不写g_flag = false，最终无法ac
例如案例：[1] 0
没写时不通过，我的输出是true，答案是false
但是我测试时，我的输出与答案是相同的

### 代码

```c
bool g_flag = false;

void dfs(struct TreeNode *root, int val, int sum)
{
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL && val == sum)
       g_flag = true;
    dfs(root->left, val, sum);
    dfs(root->right, val, sum);
}

bool hasPathSum(struct TreeNode* root, int sum){
    g_flag = false;
    dfs(root, 0, sum);
    return g_flag;
}

```
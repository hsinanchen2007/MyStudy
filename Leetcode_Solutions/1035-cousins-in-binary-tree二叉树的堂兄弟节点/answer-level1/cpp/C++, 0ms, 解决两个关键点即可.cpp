1. 用全局变量保存第一次找到的深度和父元素值, 当然也可以传参, 或者用map, 反正就是记录
2. 在找到第一个的情况下, 当前深度比第一个深度大就直接没有比较的必要了
没有考虑第2个条件时的时候成绩是4ms, 规避后0ms

Runtime: 0 ms, faster than 100.00% of C++ online submissions for Cousins in Binary Tree.
Memory Usage: 11.2 MB, less than 100.00% of C++ online submissions for Cousins in Binary Tree.
```
int depth = 0;
int parent = 0;
bool isCousins(TreeNode* root, int x, int y) {
    if (root == NULL || root->val == x || root->val == y)
    {
        return false;
    }

    return dfs(root->left, x, y, 2, root->val) || dfs(root->right, x, y, 2, root->val);
}

bool dfs(TreeNode* root, int x, int y, int curDepth, int curParent)
{
    if (root == NULL || (depth != 0 && curDepth > depth))
    {
        return false;
    }

    if (root->val == x || root->val == y)
    {
        if (depth == 0)
        {
            depth = curDepth;
            parent = curParent;
            return false;
        }
        else
        {
            return depth == curDepth && parent != curParent;
        }
    }
    return dfs(root->left, x, y, curDepth + 1, root->val) || dfs(root->right, x, y, curDepth + 1, root->val);
}
```
